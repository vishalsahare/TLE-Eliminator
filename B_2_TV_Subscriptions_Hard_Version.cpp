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
    int n, k, d;
    cin >> n >> k >> d;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int l = 0, r = 0;
    int res = INT_MAX;
    map<int, int> mp;

    while (r < n) {
        mp[A[r]]++;

        if (r - l + 1 > d) {
            mp[A[l]]--;
            if (mp[A[l]] == 0) {
                mp.erase(A[l]);
            }
            l++;
        }

        int uniq = mp.size();
        if (r - l + 1 == d) {
            res = min(res, uniq);
        }

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