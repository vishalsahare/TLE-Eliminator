#ifndef ONLINE_JUDGE
#include "debugger.hpp"
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

void treeWalkDfs(int node, int parent, vector<vector<int>> &tree,
                 vector<int> &subOrdinates) {
    int nSubOrd = 0;
    for (auto child : tree[node]) {
        if (child != parent) {
            treeWalkDfs(child, node, tree, subOrdinates);
            nSubOrd += 1 + subOrdinates[child];
        }
    }

    subOrdinates[node] = nSubOrd;
}

void solve() {
    int n;
    cin >> n;
    vector<int> subOrdinates(n + 1, 0);
    vector<vector<int>> tree(n + 1);

    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        tree[par].push_back(i);
    }

    treeWalkDfs(1, -1, tree, subOrdinates);

    for (int i = 1; i <= n; i++) {
        cout << subOrdinates[i] << " ";
    }
}

//------------
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./error.txt", "w", stderr);
    freopen("./output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}