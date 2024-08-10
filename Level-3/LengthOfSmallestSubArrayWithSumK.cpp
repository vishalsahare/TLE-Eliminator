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
    int n, K;
    cin >> n >> K;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // debug(A, n);

    // smallest subarray with sum at least K
    // fixing starting point and moving it one step forward in every iteration

    /*
        int l = 0, r = -1;
        int sum = 0;
        int res = INT_MAX;

        // invariance segment from left to right is good
        while (l < n) {
            while (r + 1 < n and sum < K) {
                r++;
                sum += A[r];
            }

            if (sum >= K) {
                res = min(res, r - l + 1);
            }

            sum -= A[l];
            l++;
        }

        cout << res;
    */

    /*
        // finding the ending point and moving it by 1 step forward
        int l = 0, r = 0;
        int sum = 0;
        int res = INT_MAX;

        for (int r = 0; r < n; r++) {
            sum += A[r];

            while (l <= r and sum - A[l] >= K) {
                sum -= A[l];
                l++;
            }

            if (sum >= K) {
                res = min(res, r - l + 1);
            }
        }

        cout << res;

    */

    // The most optimal way to code, covers all edge cases
    int res = INT_MAX;
    int sum = 0;
    int l = 0, r = 0;

    while (r < n) {
        sum += A[r];

        while (l <= r and sum >= K) {
            res = min(res, r - l + 1);
            sum -= A[l];
            l++;
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