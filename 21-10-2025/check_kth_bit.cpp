#include <bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k) {
    return (n & (1 << k)) != 0;
}

int main() {
    cout << checkKthBit(5, 0) << "\n"; // 1 (5 = 101)
    cout << checkKthBit(5, 2) << "\n"; // 1
    cout << checkKthBit(5, 1) << "\n"; // 0
    return 0;
}
