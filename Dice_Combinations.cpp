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

void solve() {
    int n;
    cin >> n;

    // STATE: no of ways to get the sum of n
    vector<int> dp(n + 1, 0);

    // BASE CONDITION: no of ways to get the sum of 0
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        cout << dp[0] << " ";
        for (int j = 1; j <= 6; j++) {
            if (j <= i) {
                // TRANSITION: no of ways from n - 1, n - 2, .... , n - n
                dp[i] = (dp[i] + dp[i - j]) % MOD;
                cout << dp[j] << " ";
            }
        }

        cout << endl;
    }

    // FINAL SUBPROBLEM:
    cout << dp[n];
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