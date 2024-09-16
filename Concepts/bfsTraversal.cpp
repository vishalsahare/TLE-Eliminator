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

void dfs(int node, int parent, vector<vector<int>>& adj) {
    cout << node << " ";
    for (auto child : adj[node]) {
        if (child != parent) {
            dfs(child, node, adj);
        }
    }
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

    vector<int> bfsTraversal;
    vector<int> visited(n + 1, false);
    queue<int> q;
    int root = 1;
    q.push(root);
    visited[root] = true;
    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        bfsTraversal.push_back(currNode);

        for (auto nei : adj[currNode]) {
            if (!visited[nei]) {
                visited[nei] = true;
                q.push(nei);
            }
        }
    }

    for (int i = 0; i < bfsTraversal.size(); i++) {
        cout << bfsTraversal[i] << " ";
    }
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