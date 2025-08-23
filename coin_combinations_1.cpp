// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define all(x) x.begin(), x.end()
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef pair<int, int> ii;
const int oo = 1e9 + 7;
 
void solve(long long n, long long x) { 
  long long *answers = new long long[x + 1];
  long long ans = 0;
  long *Cs = new long[n];
  long long relevantC = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> Cs[i];
  }
  sort(Cs, Cs + n);
 
  for (int i = 1; i < x + 1; i++)
  {
     ans = 0;
    if (i == Cs[relevantC])
    {
      relevantC++;
      ans++;
    }
 
    for (int j = 0; j < relevantC; j++)
    {
      ans += (answers[i - Cs[j]]);
    }
    answers[i] = ans % oo;
  }
 
    for (int i = 1; i < x + 1; i++)
  {
    //cout << answers[i] << " ";
  }
  //cout << endl;
  cout << answers[x] << endl;
  delete[] answers;
  delete[] Cs;
 }
 
signed main() {
  //cin.tie(NULL)->sync_with_stdio(false);
  //cout << setprecision(10);
  long long n, x;
  cin >> n >> x;
  solve(n, x);
}