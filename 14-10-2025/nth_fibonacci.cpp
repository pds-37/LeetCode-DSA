#include <bits/stdc++.h>
using namespace std;


int nthFibonacci(int n) {
    if (n == 0 || n == 1) return n;
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

int main() {
    int n = 10;
    cout << "Fib(" << n << ") = " << nthFibonacci(n) << "\n"; 
    return 0;
}
