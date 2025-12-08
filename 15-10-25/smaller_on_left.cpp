#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result;
    result.reserve(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        auto it = s.lower_bound(arr[i]); // first >= arr[i]
        if (it == s.begin()) result.push_back(-1);
        else {
            --it;
            result.push_back(*it);
        }
        s.insert(arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {2, 3, 1, 5};
    vector<int> res = Smallestonleft(arr);
    for (int x : res) cout << x << " ";
    cout << "\n"; // expected -1 2 -1 3
    return 0;
}
