#include <bits/stdc++.h>
using namespace std;

// Assumes input is lowercase 'a'-'z'. Non-lowercase chars are ignored.
char getMaxOccuringChar(const string& s) {
    vector<int> freq(26, 0);
    for (char ch : s) {
        if ('a' <= ch && ch <= 'z') freq[ch - 'a']++;
        else if ('A' <= ch && ch <= 'Z') freq[ch - 'A']++; // also count uppercase
    }
    int mx = 0; char res = 'a';
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > mx) { mx = freq[i]; res = char('a' + i); }
    }
    return res;
}

int main() {
    cout << getMaxOccuringChar("aabbccc") << "\n"; // c
    cout << getMaxOccuringChar("Hello World!") << "\n"; // l
    return 0;
}
