// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
void answer(ll x, ll y)
{
    ll ma = max(x, y);
    if (ma % 2 == 0)
    {
        if (x > y)
        {
            cout << (ma-1)*(ma-1) + y << endl;
        }
        else
        {
            cout << 1 + ma*ma -x << endl;
        }
    }
    else
    {
        if (x > y)
        {
            cout << 1 + ma*ma - y << endl;
        }
        else
        {
            cout << (ma - 1)*(ma - 1) + x << endl;
        }
    }
}
 
int main(){
    int t;
    cin >> t;
    ll x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> y;
        cin >> x;
        answer(x, y);
    }
 
    return 0;
}