#include <bits/stdc++.h>
//#include <pair>
using namespace std;
typedef long long ll;
#define x first
#define y second
 
 
 
 
void solve()
{
	pair<ll, ll> p1, p2, p3;
	cin >> p1.first >> p1.second >> p2.first >> p2.second
	>> p3.first >> p3.second;
 
	if (p1.first == p2.first)
	{
		if (p1.y > p2.y)
		{
			if (p3.first < p1.first)
			{
				cout << "RIGHT" << endl;
			}
			else if (p3.first > p1.first)
			{
				cout << "LEFT" << endl;
			}
			else
			{
				cout << "TOUCH" << endl;
			}
		}
 
		else
		{
			if (p3.first > p1.first)
			{
				cout << "RIGHT" << endl;
			}
			else if (p3.first < p1.first)
			{
				cout << "LEFT" << endl;
			}
			else
			{
				cout << "TOUCH" << endl;
			}
		}
	}
 
	else
	{
		pair<ll,ll> a = {p3.x - p1.x, p3.y - p1.y};
		pair<ll, ll> b = {p3.x - p2.x, p3.y - p2.y};
		ll crossy = a.x * b.y - a.y * b.x;
 
		ll crossy2 = a.x * b.y - a.y * b.x;
		
		if (crossy2 > 0)
		{
			cout << "LEFT" << endl;
		}
		else if (crossy2 < 0)
		{
			cout << "RIGHT" << endl;
		}
		else
		{
			cout << "TOUCH" << endl;
		}
	}
}
 
 
 
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}
}