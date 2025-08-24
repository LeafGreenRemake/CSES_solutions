// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define all(x) x.begin(), x.end()
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef pair<int, int> ii;
const int oo = 1e9 + 7;
 
#include <bits/stdc++.h>
using namespace std;
 
void solve(int n) { 
    vector<int> vec;
    vector<int> d;
    int length = 0, x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
        d.push_back(oo);
    }
 
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(d.begin(), d.end(), vec[i]);
        //cout << "this *it is " << *it << endl;
        if (d[length] < vec[i])
        {
            length++;
            d[length] = vec[i];
        }
        else
        {
            *it = vec[i];
            //cout << "*it updated to " << *it << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        //cout << d[i] << " ";
    }
    //cout << endl;
    cout << length + 1 << endl;
}
 
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout << setprecision(10);
    int n;
    cin >> n;
    solve(n);
}