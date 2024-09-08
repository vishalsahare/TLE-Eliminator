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

// ll process(ll i, vector<ll> &blocks, vector<ll> &dp, ll n) {
//     // if (dp[i] != -1) {
//     //     return dp[i];
//     // }

//     if (i >= n) {
//         return 0;
//     }

//     // dp[i] = dp[i]

//     long long pick = 1e9;
//     // cout << pick << endl;
//     if (i + blocks[i] <= n - 1) {
//         pick = process(i + blocks[i] + 1, blocks, dp, n);
//     }
//     ll noPick = process(i + 1, blocks, dp, n) + 1;

//     ll res = min(pick, noPick);
//     return res;
// }

// ll process(ll i, vector<ll> &blocks, vector<ll> &dp, ll n) {
//     if (dp[i] != -1) {
//         return dp[i];
//     }

//     if (i >= n) {
//         return 0;
//     }

//     // dp[i] = dp[i]

//     long long pick = 1e9;
//     // cout << pick << endl;
//     if (i + blocks[i] <= n - 1) {
//         pick = process(i + blocks[i] + 1, blocks, dp, n);
//     }
//     ll noPick = process(i + 1, blocks, dp, n) + 1;

//     dp[i] = min(pick, noPick);
//     return dp[i];
// }

void iprocess(vector<ll> &blocks, ll n) {
    vector<ll> dp(n, 0);
    dp[n - 1] = 1;

    for (ll i = n - 2; i >= 0; i--) {
        ll pick = 1e9;

        if (i + blocks[i] < n) {
            pick = dp[i + blocks[i] + 1];
        }
        ll noPick = 1 + dp[i + 1];
        // cout << i << "  " << pick << "  " << noPick << endl;
        dp[i] = min(pick, noPick);
        // cout << i << " " << dp[i] << endl;
    }

    // debug(dp);
    // for (int i = 0; i < n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    cout << dp[0];
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> blocks(n);

    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }

    // vector<ll> dp(n, -1);

    // dp[n - 1] = 1;
    // ll res = process(0, blocks, dp, n);

    // debug(dp);
    // cout << dp[0];

    iprocess(blocks, n);
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
    cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}