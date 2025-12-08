#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr, int m) {
    int i = m + 1;
    int j = arr.size() - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    reverseArray(arr, 2); // reverse after index 2

    for (int x : arr) cout << x << " ";
    return 0;
}
