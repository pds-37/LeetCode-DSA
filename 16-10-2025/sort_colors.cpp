#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int x : nums) {
        if (x == 0) ++count0;
        else if (x == 1) ++count1;
        else ++count2;
    }
    int i = 0;
    while (count0--) nums[i++] = 0;
    while (count1--) nums[i++] = 1;
    while (count2--) nums[i++] = 2;
}

int main() {
    vector<int> arr = {2,0,2,1,1,0};
    sortColors(arr);
    for (int x : arr) cout << x << " ";
    cout << "\n"; // 0 0 1 1 2 2
    return 0;
}
