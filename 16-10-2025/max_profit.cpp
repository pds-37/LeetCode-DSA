#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int buyPrice = INT_MAX;
    int maxProfit = 0;
    for (int p : prices) {
        if (p > buyPrice) maxProfit = max(maxProfit, p - buyPrice);
        else buyPrice = p;
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << "\n"; // 5
    return 0;
}
