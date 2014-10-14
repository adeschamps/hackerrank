#include <iostream>

int main ()
{
	const ulong mod_value = 1000000007;

	uint T;
	std::cin >> T;
	while (T--)
	{
		ulong N;
		std::cin >> N;

		ulong ans = 2;
		for (ulong i = 0; i != N; ++i)
		{
			ans %= mod_value;
			ans <<= 1;
		}
		ans += 2;
		ans %= mod_value;

		std::cout << ans << '\n';
	}
}
