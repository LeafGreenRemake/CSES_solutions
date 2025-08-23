// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
 
bool check(int n, int t, long long mid, vector<int> vec)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += mid / vec[i];
		if (sum >= t) { 
				break;
			}
	}
	if (sum >= t)
	{
		return true;
	}
	return false;
}
 
 
 
void solve(int n, int t, vector<int> vec)
{
    long long left = 0, time, mid, right = 1e18;
 
    while (left <= right)
    {
        mid = (left + right) / 2; // Move this line inside the loop
        if (check(n, t, mid, vec))
        {
            time = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    cout << time;
}
 
 
 
int main() {
	int n, t, x;
	vector<int> vec;
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	solve(n, t, vec);
}