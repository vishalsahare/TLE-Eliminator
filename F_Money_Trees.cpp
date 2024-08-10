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

    vector<int> fruits(n);
    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int l = 0;
    int res = 0;
    int sum = fruits[0];
    int r = 1;

    if (sum <= k) {
        res = 1;
    }

    while (r < n) {
        if (height[r - 1] % height[r] == 0) {
            sum += fruits[r];
        } else {
            sum = fruits[r];
            l = r;
        }

        while (sum > k) {
            sum -= fruits[l];
            l++;
        }

        res = max(res, r - l + 1);
        r++;
    }

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