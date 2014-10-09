#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
	std::cin >> T;
    for (int t = 0; t < T; ++t) {
		std::string str;
		std::cin >> str;
        int operations = 0;
        for (int i = 0; i < str.size() / 2; ++i)
            operations += abs(str[str.size() - 1 - i] - str[i]);
		std::cout << operations << '\n';
    }
    return 0;
}
