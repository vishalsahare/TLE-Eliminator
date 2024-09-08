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

ll process(ll target, vector<ll> &coins, vector<ll> &dp) {
    if (target == 0) {
        return 0;
    }

    if (dp[target] != -1) {
        return dp[target];
    }

    ll minCount = 1e9;
    for (int i = 0; i < coins.size(); i++) {
        if (target - coins[i] >= 0) {
            ll count = process(target - coins[i], coins, dp);
            minCount = min(minCount, count);
        }
    }

    dp[target] = minCount + 1;

    // cout << target << " " << dp[target] << endl;

    return dp[target];
}

// O(target * n)

void iProcess(ll target, vector<ll> &coins) {
    // min no. of coins used to get the target
    vector<ll> dp(target + 1, 1e9);

    // to get the sum 0, minimum no. of coins used 0
    dp[0] = 0;

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                // transition to get the min no of coins from different options
                // of target-coins[j]
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Final submissions
    cout << (dp[target] < 1e9 ? dp[target] : -1);
}

void solve() {
    ll n, target;
    cin >> n >> target;

    vector<ll> coins(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // // min number of coins from i to n
    // vector<ll> dp(target + 1, -1);
    // dp[0] = 0;

    // ll res = process(target, coins, dp);
    // cout << res;

    iProcess(target, coins);
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