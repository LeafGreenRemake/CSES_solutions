#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, pos;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
 
	while(cin >> pos)
	{
		arr[pos - 1] = 1;
	}
 
	for (int j = 0; j < n; j++)
	{
		if (arr[j] != 1)
		{
			cout << j + 1;
			j = n;
		}
	}
 
	//delete(arr);
	return 0;
}
