// Source: https://usaco.guide/general/io
 
// There are 2 option: 1. the array is ascending 2. it's descending
// 1 - the ans is i
 
// so here's the idea; keep an ans array and a bool that says which option is it.
 
// alg: make a stack that gets every element in ans[]
// for every i, we'll go through the stack until we find a smaller value 
// (we won't return the values we popped)
// and we'll keep a min variable to make sure it's the minimum
 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef pair<int, int> ii;
const int oo = 1e9 + 7;
 
void solve(int n) { 
	int* ans = new int[(int) n];
  int* arr = new int[(int) n];
  stack<int> st;
  int out;
  
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int min = arr[0];
 
  for (int i = 0; i < n; i++)
  {
    if (arr[i] <= min)
    {
      min = arr[i];
      ans[i] = 0;
    }
    else
    {
      for (int j = 0; j < n; j++)
      {
        if (arr[st.top() - 1] < arr[i])
        {
          ans[i] = st.top();
          j = n;
        }
        else
        {
          st.pop();
        }
      }
    }
    st.push(i + 1);
  }
 
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
	delete[] ans;
  delete[] arr;
 }
 
signed main() {
  cin.tie(NULL)->sync_with_stdio(false);
  cout << setprecision(10);
  
  int n;
  cin >> n;
  solve(n);
}