#include <bits/stdc++.h>
using namespace std;


long long reverseExponentiation(int n) {
    int temp = n;
    long long rev = 0;
    while (temp > 0) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }
    long long result = 1;
    for (long long j = 0; j < rev; j++) {
        result *= n;
        
    }
    return result;
}

int main() {
    int n = 12;
    
    n = 2;
    cout << reverseExponentiation(n) << "\n"; 
    return 0;
}
