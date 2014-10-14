#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>

struct wizard
{
	std::set<int> from;
	std::set<int> to;

	void cast (std::vector<int> & skills, int f, int t)
	{
#if DEBUG
		std::cout << "Cast from " << f << " to " << t << '\n';
#endif
		--skills[f];
		from.erase(f);
		++skills[t];
		to.erase(t);
	}
};

// Remove wizards who have run out of transformations
void retire (std::list<wizard> & wizards)
{ wizards.remove_if([] (wizard const & w) { return w.from.empty() || w.to.empty(); }); }

// struct skill
// {
// 	int have = 0;
// 	int want = 0;
// 	// std::list<int> requests;
// 	std::queue<int> requests;
// };

// struct request
// {
// 	int from;
// 	int to;
// }

std::istream & operator >> (std::istream & is, wizard & w)
{
	int count;
	int skill;

	is >> count;
	for (int i = 0; i != count; ++i)
	{
		is >> skill;
		w.from.insert(skill-1);
	}

	is >> count;
	for (int i = 0; i != count; ++i)
	{
		is >> skill;
		w.to.insert(skill-1);
	}

	return is;
}

int main ()
{
	int N, T;
	std::cin >> N >> T;

	std::vector<int> skillsets (N);
	for (int n = 0; n != N; ++n)
		std::cin >> skillsets[n];

	std::list<wizard> wizards;
	for (int t = 0; t != T; ++t)
	{
		wizard w;
		std::cin >> w;
		wizards.push_back(std::move(w));
	}

#if DEBUG
	std::cout << "Skills:\n";
	for (int s : skillsets)
		std::cout << s << '\t';
	std::cout << '\n';

	std::cout << "Wizards: " << wizards.size() << "\n";
	for (wizard const & w : wizards)
	{
		for (int s : w.from)
			std::cout << s << '\t';
		std::cout << "==>\t";
		for (int s : w.to)
			std::cout << s << '\t';
		std::cout << '\n';
	}
	std::cout << '\n';
#endif

	// int max_depth = 1;
	for (int to = 0; to != N; ++to)
		if (skillsets[to] == 0)
		{
#if DEBUG
			std::cout << "want skill in " << to << '\n';
#endif
			for (wizard & w : wizards)
				if (w.to.count(to))
				{
#if DEBUG
					std::cout << "Maybe a wizard can help\n";
#endif
					for (int from = 0; from != N; ++from)
						if (skillsets[from] > 0 && w.from.count(from))
						{
							w.cast (skillsets, from, to);
						}
				}
			retire (wizards);
		}




#if DEBUG
	std::cout << "Skills:\n";
	for (int s : skillsets)
		std::cout << s << '\t';
	std::cout << '\n';

	std::cout << "Wizards: " << wizards.size() << "\n";
	for (wizard const & w : wizards)
	{
		for (int s : w.from)
			std::cout << s << '\t';
		std::cout << "==>\t";
		for (int s : w.to)
			std::cout << s << '\t';
		std::cout << '\n';
	}
#endif

}
