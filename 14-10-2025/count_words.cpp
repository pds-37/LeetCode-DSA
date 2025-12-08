#include <bits/stdc++.h>
using namespace std;

int countWords(const string &str) {
    if (str.empty()) return 0;
    int n = str.size();
    int spaces = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == ' ') spaces++;
    return spaces + 1;
}

int main() {
    string str = "HI MY NAME IS PRIYANSHU TIWARI AND I AM IN CSE 3RD YR ";
    cout << "Number of words are " << countWords(str) << "\n";
    return 0;
}
