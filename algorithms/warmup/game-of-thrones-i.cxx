#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {

    string s;
    cin>>s;

    int flag = 0;
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string

	std::vector<int> frequency (26);
    for (char c : s) ++frequency[c-'a'];
    flag = (std::accumulate(frequency.begin(), frequency.end(),
                            0, [] (int sum, int item) { return sum + item%2; }) <= 1 ?
			1 : 0);


    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
