#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int T;
    scanf ("%d", &T);

    while (T--)
	{
		int N;
		scanf ("%d", &N);
	    long * indices = malloc (N * sizeof(long));
	    long * weights = malloc (N * sizeof(long));

	    long * sums = malloc(N * sizeof(long));
	    for (int n=0; n != N; ++n)
			sums[n] = 0;

	    // Read data
	    for (int n=0; n != N; ++n)
			scanf ("%ld", indices + n);

	    for (int n=0; n != N; ++n)
			scanf ("%ld", weights + n);



	    long max_weight = 0;

	    for (int n=N-1; n >= 0; --n)
		{
		    for (int i=n+1; i < N; ++i)
				if (indices[i] > indices[n]
					&& sums[i] > sums[n])
					sums[n] = sums[i];
		    sums[n] += weights[n];

		    if (sums[n] > max_weight)
				max_weight = sums[n];
		}

	    printf ("indices:\t");
	    for (int n=0; n != N; ++n)
			printf ("%ld\t", indices[n]);
	    printf ("\n");

	    printf ("weights:\t");
	    for (int n=0; n != N; ++n)
			printf ("%ld\t", weights[n]);
	    printf ("\n");

	    printf ("max_sum:\t");
	    for (int n=0; n != N; ++n)
			printf ("%ld\t", sums[n]);
	    printf ("\n");

	    printf ("max: %ld\n", max_weight);





	    free (indices);
	    free (weights);
	    free (sums);
	}

    return 0;
}
