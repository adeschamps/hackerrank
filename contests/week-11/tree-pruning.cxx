#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct node
{
	long weight;
	long subtree_weight;
	int parent;
	std::set<int> connections;
	bool alive = true;
};

std::vector<node> nodes;

struct node_comp {
	bool operator () (int a, int b) const
	{ return nodes[a].subtree_weight < nodes[b].subtree_weight;	}
} my_node_comp;

void find_parents (int p, int n)
{
	nodes[n].connections.erase(p);
	nodes[n].parent = p;
	for (int c : nodes[n].connections)
		find_parents (n, c);
}

void calc_weights (int n)
{
	nodes[n].subtree_weight = nodes[n].weight;
	for (int c : nodes[n].connections)
	{
		calc_weights (c);
		nodes[n].subtree_weight += nodes[c].subtree_weight;
	}
}

void kill_children (int n)
{
	if (nodes[n].alive)
		for (int c : nodes[n].connections)
			kill_children(c);
	nodes[n].alive = false;
}

void remove_node (int n)
{
	long weight = nodes[n].subtree_weight;
	kill_children(n);
	for (int p = nodes[n].parent; p != 0; p = nodes[p].parent)
		nodes[p].subtree_weight -= weight;
	nodes[0].subtree_weight -= weight;
}

int main ()
{
	int N, K;
	std::cin >> N >> K;

	nodes.resize(N);
	for (int n = 0; n != N; ++n)
		std::cin >> nodes[n].weight;

	for (int n = 1; n != N; ++n)
	{
		int a, b;
		std::cin >> a >> b;
		nodes[a-1].connections.insert(b-1);
		nodes[b-1].connections.insert(a-1);
	}

	nodes[0].parent = 0;
	for (int c : nodes[0].connections)
		find_parents (0, c);
	calc_weights (0);

#if DEBUG
	for (int n = 0; n != N; ++n)
	{
		std::cout << n+1 << ":  " << nodes[n].subtree_weight << " :\t";
		for (int c : nodes[n].connections)
			std::cout << c+1 << ' ';
		std::cout << '\n';
	}
#endif

	std::vector<int> nodes_by_weight (N);
	for (int n = 0; n != N; ++n)
		nodes_by_weight[n] = n;
	std::sort(nodes_by_weight.begin(), nodes_by_weight.end(), my_node_comp);


#if DEBUG
	for (int n : nodes_by_weight)
		std::cout << n+1 << ' ';
	std::cout << '\n';
#endif

	int count = 0;
	int index = 0;
	while (index != N && nodes[nodes_by_weight[index]].subtree_weight < 0 && count < K)
	{
#if DEBUG
		std::cout << "considering " << nodes_by_weight[index]+1 << '\n';
#endif
		if (nodes[nodes_by_weight[index]].alive)
		{
#if DEBUG
			std::cout << "killing " << nodes_by_weight[index]+1 << '\n';
#endif
			remove_node(nodes_by_weight[index]);
			++count;
			std::sort(nodes_by_weight.begin(), nodes_by_weight.end(), my_node_comp);
			index = 0;
#if DEBUG
			for (int n : nodes_by_weight)
				if (nodes[n].alive)
					std::cout << n+1 << ' ';
			std::cout << '\n';
#endif
		}
		else
			++index;
	}

#if DEBUG
	std::cout << "count: " << count << '\n';
	std::cout << "weight: " << nodes[0].subtree_weight << '\n';
#else
	std::cout << nodes[0].subtree_weight << '\n';
#endif
}
