// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
 
long long solve(int n, vector<int> vec)
{
	sort(vec.begin(), vec.end());
	long long price = 0;
	long long mid = vec[(n)/2];
	for (int i =  0; i < n; i++)
	{
		price += abs((long long)mid - vec[i]);
	}
	return price;
}
 
 
int main() {
	int n, x;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
 
	cout << solve(n, vec);
}