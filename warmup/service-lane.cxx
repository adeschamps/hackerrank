#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, T;
	std::cin >> N >> T;

    // Read array
	std::vector<int> lane (N);
    for (int n = 0; n != N; ++n)
		std::cin >> lane[n];

    // Consider cases
    for (int t=0; t != T; ++t) {
		int i, j;
		std::cin >> i >> j;

        int biggest = 3;
        for (int segment = i; segment <= j && biggest > 1; ++segment)
            if (lane[segment] < biggest) biggest = lane[segment];
		std::cout << biggest << '\n';
    }
    return 0;
}
