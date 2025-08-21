#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(long n, int arr[]) 
{ 
    int maxSoFar = -pow(10,9), maxTilHere = 0;
    
    for (int i = 0; i < n; i++)
    {
        maxTilHere = maxTilHere + arr[i];
        if (maxSoFar < maxTilHere)
        {
            maxSoFar = maxTilHere;
        }
         if (maxTilHere < 0)
        {
            maxTilHere = 0;
        }
    }
 
    cout << maxSoFar << endl;
}
 
 
int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout << setprecision(10);
 
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(n, arr);
    delete[] arr;
 
    return 0;
}