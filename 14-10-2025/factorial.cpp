#include <bits/stdc++.h>
using namespace std;

// Note: for larger n, use big integer library. Here we use long long.
long long factorial(int n) {
    long long res = 1;
    while (n > 0) {
        res *= n;
        n--;
    }
    return res;
}

int main() {
    int n = 10;
    cout << "Factorial of " << n << " is " << factorial(n) << "\n"; // 3628800
    return 0;
}
