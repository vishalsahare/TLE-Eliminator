#ifndef ONLINE_JUDGE
#include "../debugger.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

//------------
#define endl "\n"
#define ll long long

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &heights,
         vector<int> &maxLengths) {
    pair<int, int> maxHeight = {0, 0};

    for (auto child : adj[node]) {
        if (child != parent) {
            dfs(child, node, adj, heights, maxLengths);

            heights[node] = max(heights[node], heights[child] + 1);

            if (heights[child] >= maxHeight.first) {
                maxHeight = {heights[child], maxHeight.first};
            } else if (heights[child] > maxHeight.second) {
                maxHeight.second = heights[child];
            }
        }
    }

    maxLengths[node] = maxHeight.first + maxHeight.second + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        // cout << u << " " << v << endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> heights(n + 1, 1), maxLengths(n + 1);
    dfs(1, -1, adj, heights, maxLengths);

    for (int i = 1; i <= n; i++) {
        cout << i << " : " << maxLengths[i] << endl;
    }

    cout << "Diameter : " << *max_element(maxLengths.begin(), maxLengths.end());
}

//------------
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../error.txt", "w", stderr);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}