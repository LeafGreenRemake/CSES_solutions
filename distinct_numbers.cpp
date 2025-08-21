#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef pair<int, int> ii;
const int oo = 1e9 + 7;
 
//Main idea: save a map with the given numbers as keys,
//and the number of their instances as data.
 
int solve(int n, map<int, bool> exists, int &count) 
{ 
  int num;
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    if (exists[num] == NULL)
    {
      count++;
      exists[num] = true;
    }
  }
  return count;
}
 
signed main() {
  cin.tie(NULL)->sync_with_stdio(false);
  cout << setprecision(10);
  int n;
  cin >> n;
  int count = 0;
  map<int, bool> exists; 
  cout << solve(n, exists, count) << endl;
 
	return 0;
}
