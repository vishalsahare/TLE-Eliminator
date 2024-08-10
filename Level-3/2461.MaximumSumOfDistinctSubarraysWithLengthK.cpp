#ifndef ONLINE_JUDGE
#include "../debugger.hpp"
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

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int res = 0;
    int sum = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        // add new elem to window
        sum += A[i];
        mp[A[i]]++;

        // remove 1st elem from window
        if (i >= k) {
            mp[A[i - k]]--;
            sum -= A[i - k];

            // debug(A[i - k]);
            // debug(mp.count(A[i - k]));

            if (mp[A[i - k]] == 0) {
                mp.erase(A[i - k]);
            }
        }

        // debug(mp);

        // update res
        if (i >= k - 1 and mp.size() == k) {
            res = max(res, sum);
        }
    }

    cout << res;
}

//------------
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../error.txt", "w", stderr);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}