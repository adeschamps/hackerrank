#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
	std::cin >> N;
	std::vector<int> present_in_all (26, 1);
    for (int n = 0; n < N; ++n) {
		std::string str;
		std::cin >> str;
        for (char c = 'a'; c <= 'z'; ++c)
            if (present_in_all[c-'a'] == 1 && str.find(c) == std::string::npos)
                present_in_all[c-'a'] = 0;
    }
	std::cout << std::accumulate(present_in_all.begin(), present_in_all.end(), 0) << '\n';
    return 0;
}
