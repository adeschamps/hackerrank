#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int N;
	scanf ("%d", &N);
	int * arr = malloc (N * sizeof(int));
	for (int i = 0; i != N; ++i)
		scanf ("%d", arr + i);

	int swaps = 0;
	for (int i = 1; i != N; ++i)
	{
		int j = i;
		while (arr[j] < arr[j-1])
		{
			arr[j] = arr[j] ^ arr[j-1];
			arr[j-1] = arr[j] ^ arr[j-1];
			arr[j] = arr[j] ^ arr[j-1];
			++swaps;
			--j;
		}
	}
	printf ("%d\n", swaps);

	free (arr);
}
