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

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &distance,
         int dist) {
    distance[node] = dist;

    for (auto child : adj[node]) {
        if (child != parent) {
            dfs(child, node, adj, distance, dist + 1);
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
    vector<int> distance(n + 1, 0);
    dfs(1, -1, adj, distance, 0);

    int firstEp = 1, secondEp = 1;
    for (int i = 1; i <= n; i++) {
        // cout << i << " : " << distance[i] << endl;
        if (distance[i] > distance[firstEp]) {
            firstEp = i;
            // cout << i << "=>" << firstEp << endl;
        }
    }
    // cout << "firstEp: " << firstEp << endl;

    distance.clear();
    dfs(firstEp, -1, adj, distance, 0);

    for (int i = 1; i <= n; i++) {
        // cout << i << " : " << distance[i] << endl;
        if (distance[i] > distance[secondEp]) {
            secondEp = i;
        }
    }

    cout << firstEp << " " << secondEp << "=>" << distance[secondEp] + 1;
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