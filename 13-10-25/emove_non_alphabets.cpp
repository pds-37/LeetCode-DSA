#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeNonAlphabets(string s) {
        string res = "";
        for (char c : s) {
            if (isalpha(c))
                res += c;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.removeNonAlphabets("H3e!!l@l#o$ W0or1ld");
    return 0;
}
