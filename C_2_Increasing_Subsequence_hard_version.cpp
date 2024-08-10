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
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int l = 0;
    int r = n - 1;
    string res;
    string left;
    string right;

    while (l <= r) {
        if (A[l] < A[r]) {
            res += 'L';
            l++;
        } else if (A[l] > A[r]) {
            res += 'R';
            r--;
        } else {
            for (int i = l + 1; i <= r; i++) {
                if (A[i] < A[i + 1]) {
                    left += 'L';
                } else {
                    left += 'L';
                    break;
                }
            }
            for (int i = r; i >= l; i--) {
                if (A[i] < A[i - 1]) {
                    right += 'R';
                } else {
                    right += 'R';
                    break;
                }
            }
            // debug(left);
            // debug(right);
            res += (left.size() > right.size() ? left : right);
            break;
        }

        // debug(res);
    }

    cout << res.size() << endl;
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
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}