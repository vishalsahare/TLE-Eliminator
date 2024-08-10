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

// Recursive

// int combinations(int target, vector<int> &coins, vector<int> &dp) {
//     if (dp[target] != -1) {
//         return dp[target];
//     }

//     if (target == 0) {
//         return 1;
//     }

//     int ways = 0;
//     for (int j = 0; j < coins.size(); j++) {
//         if (target - coins[j] >= 0) {
//             // debug(target);
//             ways = (ways + combinations(target - coins[j], coins, dp)) % MOD;
//             // debug(j);
//             // debug(res);
//         }
//     }

//     // cout << res << endl;
//     dp[target] = ways;
//     return ways;
// }

// void solve() {
//     int n, target;
//     cin >> n >> target;

//     vector<int> coins(n, 0);

//     for (int i = 0; i < n; i++) {
//         cin >> coins[i];
//     }

//     vector<int> dp(target + 1, -1);

//     int res = 0;
//     res = combinations(target, coins, dp);
//     cout << res;
// }

void solve() {
    int n, target;
    cin >> n >> target;

    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // No. of ways to get the sum at ith
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    cout << dp[target];
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