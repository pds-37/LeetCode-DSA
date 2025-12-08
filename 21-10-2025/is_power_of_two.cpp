#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(long long n) {
    if (n == 1) return true;
    if (n <= 0 || n % 2 != 0) return false;
    return isPowerOfTwo(n / 2);
}

int main() {
    cout << isPowerOfTwo(1) << "\n";  // 1
    cout << isPowerOfTwo(16) << "\n"; // 1
    cout << isPowerOfTwo(18) << "\n"; // 0
    return 0;
}
