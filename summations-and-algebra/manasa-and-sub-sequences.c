#include <stdio.h>

int main ()
{
	const long mod_value = 1000000007;
	long sum = 0;
	long index = 1;
	char digit;

	while (scanf("%c", &digit) != -1
		   && digit >= '0' && digit <= '9')
	{
		sum = (sum * 11 + (digit-'0') * index) % mod_value;
		index = (index * 2) % mod_value;
	}
	printf("%ld\n", sum);

	return 0;
}
