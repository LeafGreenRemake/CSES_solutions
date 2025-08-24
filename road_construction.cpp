#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef pair<int, int> ii;
const int oo = 1e8 + 7;
 
const int maxn = 100005;
int p[maxn], s[maxn];  // parent and size arrays.
 
int find(int a) { return p[a] == a ? a : p[a] = find(p[a]); }
 
int onion(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return 0;
  if (s[a] < s[b]) swap(a, b);
  s[a] += s[b];
  p[b] = a;
  return 1;
}
 
void solve(int n, int m) { 
  int a, b;
  int maxSize = 1, numOfComponents = n;
  for (int i = 0; i < n; i++)
  {
    p[i] = i;
    s[i] = 1;
  }
 
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    if ((a = find(a)) != (b = find(b))) 
    {
      numOfComponents--;
      if (s[a] < s[b]) swap(a, b);
      s[a] += s[b];
      p[b] = a;
      if (s[a] > maxSize)
      {
        maxSize = s[a];
      }
    }
    cout << numOfComponents << " " << maxSize << endl;
  }
 }
 
signed main() {
  cin.tie(NULL)->sync_with_stdio(false);
  cout << setprecision(10);
  int n, m;
  cin >> n >> m;
  solve(n, m);
}