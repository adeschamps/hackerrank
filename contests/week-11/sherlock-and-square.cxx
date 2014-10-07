#include <iostream>
#include <vector>
#include <map>

int main ()
{
	const long mod_value = 1000000007;
	uint T;
	std::cin >> T;

	std::map<long,int> position_map;
	std::vector<long> solutions (T);

	for (uint t = 0; t != T; ++t)
	{
		long n;
		std::cin >> n;
		position_map[n] = t;
	}

	long total = 4;
	int t = 0;
	long increment = 2;
	for (std::pair<long,int> const & pair : position_map)
	{
		while (t != pair.first)
		{
			total += increment;
			total %= mod_value;
			increment <<= 1;
			increment %= mod_value;
			++t;
		}
		solutions[pair.second] = total;
	}

	for (long l : solutions)
		std::cout << l << '\n';
}
