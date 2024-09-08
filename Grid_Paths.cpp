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
void solve() {
    ll n;
    cin >> n;

    string s;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> s;
        grid[i].assign(s);
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << grid[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    if (grid[n - 1][n - 1] == '*') {
        cout << 0;
        return;
    }

    // no of paths from i,j to n-1, n-1
    vector dp(n, vector(n, 0));
    dp[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == n - 1 and j == n - 1) {
                continue;
            }

            if (grid[i][j] == '.') {
                ll bottom = i < n - 1 ? dp[i + 1][j] : 0;
                ll right = j < n - 1 ? dp[i][j + 1] : 0;
                dp[i][j] = (bottom + right) % MOD;
            }
        }
    }

    cout << dp[0][0];
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