#include <bits/stdc++.h>
using namespace std;

int arraySum(const vector<int>& arr) {
    int sum = 0;
    for (int x : arr) sum += x;
    return sum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Sum = " << arraySum(arr) << "\n"; 
    return 0;
}
