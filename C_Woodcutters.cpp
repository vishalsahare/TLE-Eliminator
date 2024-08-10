#ifndef ONLINE_JUDGE
#include "debugger.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

//------------

#define endl "\n"
#define uint uint64_t
#define int int64_t

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------

struct Tree {
    int x;
    int h;
};

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
        return;
    }

    int x, h;
    vector<Tree> trees(n);

    for (int i = 0; i < n; i++) {
        cin >> x >> h;

        trees[i].x = x;
        trees[i].h = h;
    }

    int res = 2;
    for (int i = 1; i < n - 1; i++) {
        if (trees[i].x - trees[i].h > trees[i - 1].x) {
            res++;
        } else if (trees[i].x + trees[i].h < trees[i + 1].x) {
            trees[i].x = trees[i].x + trees[i].h;  // Making adjustment of pos to occupy segment so that next tree can detect
            res++;
        }
    }

    cout << res;
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