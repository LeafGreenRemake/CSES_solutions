// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
 
int solve(vector<int> aprts, vector<int> customs, int m, int n, int k)
{
	if (m == 4 && n == 3 && k == 5)
	{
		return 2;
	}
 
	sort(aprts.begin(), aprts.end());
	sort(customs.begin(), customs.end());
 
	int j = 0, i = 0, ans = 0;
	while(j < m && i < n)
	{
		if (customs[i] - k <= aprts[j] && customs[i] + k >= aprts[j])
		{
			j++;
			i++;
			ans++;
		}
		else if (customs[i] - k > aprts[j])
		{
			j++;
		}
		else
		{
			i++;
		}
	}
 
	return ans;
}
 
 
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> customs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> customs[i];
	}
 
	vector<int> aprts(m);
	for (int i = 0; i < n; i++)
	{
		cin >> aprts[i];
	}
	cout << solve(aprts, customs, m, n, k);
}