#include <bits/stdc++.h>
using namespace std;
 
 
struct Node {
    int min_val;
};
 
 
void build_segment_tree(vector<int>& arr, vector<Node>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node].min_val = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build_segment_tree(arr, tree, 2 * node, start, mid);
    build_segment_tree(arr, tree, 2 * node + 1, mid + 1, end);
    tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
}
 
 
void update_segment_tree(vector<Node>& tree, int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node].min_val = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update_segment_tree(tree, 2 * node, start, mid, idx, val);
    else
        update_segment_tree(tree, 2 * node + 1, mid + 1, end, idx, val);
    tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
}
 
 
int query_segment_tree(vector<Node>& tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left)
        return INT_MAX;
    if (start >= left && end <= right)
        return tree[node].min_val;
    int mid = (start + end) / 2;
    int left_min = query_segment_tree(tree, 2 * node, start, mid, left, right);
    int right_min = query_segment_tree(tree, 2 * node + 1, mid + 1, end, left, right);
    return min(left_min, right_min);
}
 
int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
 
    vector<Node> tree(4 * n);
    build_segment_tree(arr, tree, 1, 0, n - 1);
 
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            update_segment_tree(tree, 1, 0, n - 1, k - 1, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query_segment_tree(tree, 1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }
 
    return 0;
}