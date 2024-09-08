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
ll isolve(ll i, ll target, vector<ll> &coins, vector<vector<ll>> &dp) {
    if (i >= coins.size()) {
        return 0;
    }

    if (dp[i][target] > 0) {
        return dp[i][target];
    }

    if (target == 0) {
        return 1;
    }

    // pick
    ll pick = 0;
    if (target - coins[i] >= 0) {
        pick = isolve(i, target - coins[i], coins, dp);
    }

    ll notPick = isolve(i + 1, target, coins, dp);

    dp[i][target] = (pick + notPick) % MOD;

    return dp[i][target];
}

void solve() {
    ll n, finalTarget;
    cin >> n >> finalTarget;

    vector<ll> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // number of distinct ways to construct target such that
    // all coins from i to n are used and all coins before i are
    // skipped
    vector<vector<ll>> dp(n + 1, vector<ll>(finalTarget + 1, 0));

    // construct target 0 such that all coins from i to n are pickable
    for (ll i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    ll res = isolve(0, finalTarget, coins, dp);
    cout << res;
}

// void solve() {
//     ll n, finalTarget;
//     cin >> n >> finalTarget;

//     vector<ll> coins(n);

//     for (int i = 0; i < n; i++) {
//         cin >> coins[i];
//     }

//     // number of distinct ways to construct target such that
//     // all coins from i to n are used and all coins before i are skipped
//     vector<vector<ll>> dp(n + 1, vector<ll>(finalTarget + 1, 0));

//     // construct target 0 such that all coins from i to n are pickable
//     for (ll i = 0; i < n; i++) {
//         dp[i][0] = 1;
//     }

//     // {2, 3, 5}
//     // not pick -> dp[i+1][k]
//     // pick -> dp[i][k-coins[i]]
//     for (ll i = n - 1; i >= 0; i--) {
//         for (ll target = 1; target <= finalTarget; target++) {
//             ll notTaken = dp[i + 1][target];

//             ll taken = 0;
//             if (coins[i] <= target) {
//                 taken = dp[i][target - coins[i]];
//             }

//             dp[i][target] = (notTaken + taken) % MOD;
//         }
//     }

//     cout << dp[0][finalTarget];
// }

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
        // cout << endl;
    }

    return 0;
}