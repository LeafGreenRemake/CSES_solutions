// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
//idea; first enter all odd numbers, then all odd numbers 
 
int main() {
	int n;
	cin >> n;
	if (n <= 3 && n != 1)
	{
		cout << "NO SOLUTION";
	}
 
	else
	{
		int i = 2;
		while(i <= n)
		{
			cout << " " << i;
			i += 2;
		}
 
		i = 1;
		while (i <= n)
		{
			cout << " " << i;
			i += 2;
		}
	}
	
	return 0;
}
