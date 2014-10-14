#include <iostream>
#include <set>
#include <vector>

struct num
{
	unsigned long val;
	uint len;
};

bool operator < (num const & a, num const & b)
{
	return a.val < b.val;
}

int main ()
{
	std::vector<unsigned long> pow10;
	for (unsigned long i = 1; i < 1000000000000000000; i *= 10)
		pow10.push_back(i);

	std::set<num> strangers;
	for (unsigned long i = 0; i != 10; ++i)
		strangers.insert(num{i,1});
	auto iter = strangers.begin();

	int T;
	std::cin >> T;
	while (T--)
	{
		unsigned long L, R;
		std::cin >> L >> R;

		while (iter->val < R)
		{
			if (iter->val * iter->len < pow10[iter->len])
			{
				unsigned long val = iter -> val * iter->len;
				strangers.insert(num{val, iter->len});
			}
			if (iter->val * (iter->len+1) >= pow10[iter->len])
			{
				unsigned long val = iter -> val * (iter->len+1);
				strangers.insert(num{val, iter->len+1});
			}
			++iter;
		}

		int count = 0;
		auto iter2 = strangers.begin();
		while (iter2->val < L) ++iter2;
		while (iter2->val <= R) { ++iter2; ++count; }
		std::cout << count << '\n';
	}
}
