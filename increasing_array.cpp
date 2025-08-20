// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, element, maxEl;
	long moves = 0;
	cin >> n;
	int arr[n];
	int index = 0;
	while (cin >> element)
	{
		arr[index] = element;
		index++;
	}
	maxEl = arr[0];
	for (int i = 1; i < n; i = i + 1)
	{
		if (maxEl < arr[i])
		{
			maxEl = arr[i];
		}
		else
		{
			moves += maxEl - arr[i];
		}
	}
	cout << moves;
 
	return 0;
}