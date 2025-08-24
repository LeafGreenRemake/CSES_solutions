// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef pair<int, int> ii;
const int oo = 1e9 + 7;
 
 
struct seg {
  seg *left = NULL, *right = NULL;
  int lo, hi, mi, v = 0;
 
  seg(int lo, int hi) : lo(lo), hi(hi), mi((lo + hi) / 2) {
    if (lo < hi)
      left = new seg(lo, mi), right = new seg(mi + 1, hi);
  }
 
  int query(int i) {
    // get the value of the i-th element, by recursivly summing
    // all O(logn) segments that have i in them.
    if (i < lo || hi < i)
      return 0;
    return v + (left ? left->query(i) : 0) + (right ? right->query(i) : 0);
  }
 
  void add(int a, int b, int d) {
    // increase all elements in the range [a,b] by +d.
    // find the "log cover" of [a,b] and add +d to those O(logn)
    // segments only.
    if (b < lo || hi < a)
      return;
    if (a <= lo && hi <= b)
      return v += d, void();
    left->add(a, b, d), right->add(a, b, d);
  }
};
 
 
void solve(int n, int q) { 
	seg *arr = new seg(0, n); // THE ERROR IS HERE
	int input, a, b, u, k;
  vi answers;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr->add(i, i, input);
  }
 
 
  for (int i = 0; i < q; i++)
  {
    cin >> input;
    if (input == 1)
    {
      cin >> a >> b >> u;
      arr->add(a - 1, b - 1, u);
    }
    else if (input == 2)
    {
      cin >> k;
      answers.push_back(arr->query(k - 1));
    }
  }
 
  for (int i = 0; i < answers.size(); i++)
  { 
    cout << answers[i] << endl;
  }
 }
 
signed main() {
  cin.tie(NULL)->sync_with_stdio(false);
  cout << setprecision(10);
  int n, q, k;
  cin >> n >> q;
  solve(n, q);
}