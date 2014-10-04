#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
	std::cin >> N;
	std::map<int,int> sticks;
	std::for_each (std::istream_iterator<int> (std::cin),
                   std::istream_iterator<int> (),
                   [&] (int length) { ++sticks[length]; });

    for (std::pair<int,int> pair : sticks) {
		std::cout << N << '\n';
        N -= pair.second;
    }
    return 0;
}
