#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> ii;
const int oo = 2e14 + 7;
 
void shortestPath(int src, int n, vector<vector<ii>>& vecOfVecs)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
 
    vi dist(n + 1, oo);
    dist[src] = 0;
 
    pq.push({0, src});
 
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
 
        if (d > dist[u]) {
            continue;
        }
 
        for (auto [v, weight] : vecOfVecs[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
 
    // distances from cities
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}
 
void solve(int n, int m) {
    vector<vector<ii>> vectorOfVecs(n + 1);
 
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        vectorOfVecs[a].push_back({b, c});
    }
 
    shortestPath(1, n, vectorOfVecs);
}
 
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout << setprecision(10);
    int n, m;
    cin >> n >> m;
    solve(n, m);
}