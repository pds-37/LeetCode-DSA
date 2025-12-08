#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(const string &s) {
    unordered_set<char> seen;
    string result;
    for (char ch : s) {
        if (!seen.count(ch)) {
            result.push_back(ch);
            seen.insert(ch);
        }
    }
    return result;
}

int main() {
    string s = "banana";
    cout << removeDuplicates(s) << "\n"; // expected "ban"
    return 0;
}
