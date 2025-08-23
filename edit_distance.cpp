// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<char> vi;
typedef pair<int, int> ii;
const int oo = 1e9 + 7;
 
void solve(string nString, string mString) { 
	int n = nString.length();
	int m = mString.length();
	int matrix[m+1][n+1];
	int x;
 
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			matrix[i][j] = 0;
		}
	}
 
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i != 0 || j != 0)
			{
				if (i != 0 && j != 0)
				{
					matrix[i][j] = min(matrix[i-1][j] + 1, matrix[i][j-1] + 1);
					x = matrix[i-1][j-1] + 1;
					if (mString[i-1] == nString[j-1])
					{
						x--;
					}
					matrix[i][j] = min(matrix[i][j], x);
				}
				else if (i != 0)
				{
					matrix[i][j] = matrix[i-1][j] + 1;
				}
				else
				{
					matrix[i][j] = matrix[i][j-1] + 1;
				}
			}
		}
	}
 
	//for (int i = 0; i <= m; i++)
	//{
	//	for (int j = 0; j <= n; j++)
	//	{
	//		cout << matrix[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	cout << matrix[m][n]<< endl;
 }
 
signed main() {
  cin.tie(NULL)->sync_with_stdio(false);
  cout << setprecision(10);
  string n, m;
  cin >> n >> m;
  solve(n, m);
}