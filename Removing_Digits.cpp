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
// ll rSolve(ll n, string num) {
//     if (n == 0) {
//         return 0;
//     }

//     // cout << n << " " << num << endl;
//     ll nCount = 1e9;

//     for (ll j = 0; j < num.size(); j++) {
//         ll digit = num[j] - '0';
//         ll count = 1e9;
//         // cout << digit << " " << num[j] << endl;
//         if (digit != 0) {
//             count = rSolve(n - digit, to_string(n - digit));
//             // cout << "count : " << count << endl;
//         }

//         nCount = min(nCount, count + 1);
//         // cout << nCount << endl;
//     }

//     return nCount;
// }

// void solve() {
//     ll num;
//     cin >> num;

//     ll res = rSolve(num, to_string(num));
//     cout << res;
// }

void solve() {
    ll num;
    cin >> num;

    // number of steps required to get number 0
    vector<ll> dp(num + 1, 1e9);
    dp[0] = 0;

    for (ll i = 1; i <= num; i++) {
        string x = to_string(i);

        for (char ch : x) {
            int digit = ch - '0';
            // cout << digit << " ";

            if (digit != 0) {
                // transition steps
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }

        // cout << "   Steps: " << dp[i] << endl;
    }
    cout << dp[num];
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