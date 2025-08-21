// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
	ll n, x;
  cin >> n;
  for (ll k = 1; k <= n; k++)
  {
    if (k == 1)
    {
      cout << 0 << endl;
    }
    else if (k == 2)
    {
      cout << 6 << endl;
    }
    else
    {
      x = 2*(k-1)*(k-2);
      cout << k*k*(k*k-1)/2 - 2*x << endl;
    }
  }
 
  return 0; 
}