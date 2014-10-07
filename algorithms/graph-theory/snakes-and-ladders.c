#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main ()
{
	int T;
	scanf ("%d", &T);
	while (T--)
	{
		int num_snakes, num_ladders;
		scanf ("%d,%d", &num_snakes, &num_ladders);
		int num_links = num_snakes + num_ladders;

		int * board = malloc (101 * sizeof(int));
		for (int i = 0; i <= 100; ++i)
			board[i] = i;
		for (int i = 0; i != num_links; ++i)
		{
			int from, to;
			scanf ("%d,%d", &from, &to);
			board[from] = to;
		}

#if DEBUG
		printf ("board:\n");
		for (int i = 0; i <= 100; ++i)
			if (board[i] != i)
				printf ("%d -> %d\n", i, board[i]);
		printf ("\n");
#endif

		int * moves_to_finish = malloc (101 * sizeof(int));
		for (int i = 0; i != 100; ++i)
			moves_to_finish[i] = INT_MAX;
		moves_to_finish[100] = 0;

		short changed;
		do
		{
			changed = 0;
			for (int i = 99; i >= 0; --i)
				for (int roll = 1; roll <= 6 && i + roll <= 100; ++roll)
				{
					int destination = board[i+roll];

					if (moves_to_finish[destination] < moves_to_finish[i] - 1)
					{
						moves_to_finish[i] = moves_to_finish[destination] + 1;
						changed = 1;
					}
				}
		}
		while (changed != 0);

#if DEBUG
		for (int i = 0; i <= 100; ++i)
			printf ("from %d: %d\n", i, moves_to_finish[i]);
#endif

#if DEBUG
		printf ("min moves: %d\n\n", moves_to_finish[0]);
#else
		printf ("%d\n", moves_to_finish[0]);
#endif

		free (board);
		free (moves_to_finish);
	}

	return 0;
}
