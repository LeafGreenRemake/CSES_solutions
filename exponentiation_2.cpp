// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
 
long long mod_pow(long long base, long long exponent, long long modulus) {
    if (base == 0 && exponent == 0)
    {
        return 1;
    }
    
    long long result = 1;
    base %= modulus;
 
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent /= 2;
        base = (base * base) % modulus;
    }
 
    return result;
}
 
 
int main() {
	long long n, a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cin >> b;
		cin >> c;
		long long result = mod_pow(a, mod_pow(b, c, MOD - 1), MOD);
        cout << result << endl;
	}
}
