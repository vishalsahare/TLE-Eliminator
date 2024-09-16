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

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &inTime,
         vector<int> &outTime, int &time) {
    inTime[node] = time;
    // cout << node << ": in - " << inTime[node] << endl;
    time++;

    for (auto child : adj[node]) {
        if (child != parent) {
            dfs(child, node, adj, inTime, outTime, time);
        }
    }

    outTime[node] = time;
    // cout << node << ": out - " << outTime[node] << endl;
    time++;
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

    vector<int> inTime(n + 1, 0), outTime(n + 1, 0);
    int time = 0;
    dfs(1, -1, adj, inTime, outTime, time);
    debug(inTime);
    debug(outTime);
    for (int i = 1; i <= n; i++) {
        // cout << i << " = " << inTime[i] << ":" << outTime[i] << endl;
    }

    int x, y;
    cin >> x >> y;
    // cout << x << " " << y << endl;
    cout << ((inTime[x] < inTime[y] and outTime[x] > outTime[y]) ? "YES"
                                                                 : "NO");
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