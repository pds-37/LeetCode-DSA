#include <bits/stdc++.h>
using namespace std;

// Sliding window: longest substring without repeating characters
int lengthOfLongestSubstring(const string& s) {
    int n = s.size();
    if (n == 0) return 0;
    unordered_map<char,int> freq;
    int left = 0, best = 0;
    for (int right = 0; right < n; ++right) {
        char c = s[right];
        freq[c]++;
        // shrink until no repetition of c
        while (freq[c] > 1) {
            freq[s[left]]--;
            ++left;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << "\n"; // expected 3 ("abc")
    cout << lengthOfLongestSubstring("bbbbb") << "\n";    // expected 1 ("b")
    cout << lengthOfLongestSubstring("pwwkew") << "\n";   // expected 3 ("wke")
    return 0;
}
