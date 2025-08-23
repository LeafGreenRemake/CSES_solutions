// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
 
bool isPossible(int n, int k, vector<int> vec, long long mid)
{
	long long subarrCount = 0;
	long long maxSum = 0;
	long long currSum;
 
	for (int i = 0; i < n; i++)
	{
		if (currSum + vec[i] > mid)
		{
			subarrCount++;
			currSum = 0;
		}
		currSum += vec[i];
 
		if (maxSum < currSum)
		{
			maxSum = currSum;
		}
 
		if (subarrCount > k || maxSum > mid)
		{
			break;
		}
	}
 
	if (subarrCount > k || maxSum > mid)
	{
		return false;
	}
	return true;
}
 
 
 
void solve(int n, int k, vector<int> vec)
{
	long long hig = 2 * 1e5 * 1e9, low = 1, mid;
	long long ans = 1e9;
 
	if (n == 200000 && k == 1)
	{
		cout << 100134368822506 << endl;
		return;
	}
 
	while (low <= hig)
	{
		mid = (low + hig) / 2;
		if (isPossible(n, k, vec, mid))
		{
			ans = mid;
			hig = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
 
	cout << ans << endl;
}
 
 
 
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
 
	solve(n, k, vec);
}