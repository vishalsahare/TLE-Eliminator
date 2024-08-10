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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    vector<vector<int> > subGroup(k, vector<int>(26));

    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        subGroup[i % k][x]++;
        // cout << x << " ";
    }

    debug(s);

    int res = 0;
    for (int i = 0; i <= k / 2; i++) {
        int mx = 0;
        for (int p = 0; p < 26; p++) {
            int temp = subGroup[i][p] + subGroup[k - 1 - i][p];
            // debug(temp);
            mx = max(mx, temp);
        }
        debug(subGroup, k);
        cout << endl;
        debug(res);
        debug(mx);
        res += mx;
    }

    res = n - res;
    cout << res;
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