#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;

    nge[n - 1] = n;
    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    vector<int> ans;
    int j = 0;

    for (int i = 0; i <= n - k; i++) {
        if (j < i) j = i;
        int maxVal = nums[j];

        while (j < i + k) {
            maxVal = nums[j];
            j = nge[j];
        }
        ans.push_back(maxVal);
    }
    return ans;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res = maxSlidingWindow(nums, 3);
    for (int x : res) cout << x << " ";
    // expected 3 3 5 5 6 7
    cout << "\n";
    return 0;
}
