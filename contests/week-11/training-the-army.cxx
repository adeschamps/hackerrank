#include <algorithm>
#include <iostream>
// #include <iterator>
#include <set>
#include <vector>

struct wizard
{
	std::set<int> from;
	std::set<int> to;

};

std::istream & operator >> (std::istream & is, wizard & w)
{
	int count;
	int skill;

	is >> count;
	for (int i = 0; i != count; ++i)
	{
		is >> skill;
		w.from.insert(skill);
	}

	is >> count;
	for (int i = 0; i != count; ++i)
	{
		is >> skill;
		w.to.insert(skill);
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

	std::vector<wizard> wizards (T);
	for (int t = 0; t != T; ++t)
		std::cin >> wizards[t];

#if DEBUG
	std::cout << "Skills:\n";
	for (int s : skillsets)
		std::cout << s << '\t';
	std::cout << '\n';

	std::cout << "Wizards:\n";
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
