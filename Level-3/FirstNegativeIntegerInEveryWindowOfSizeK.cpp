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

    // O(n*k)
    // (1)
    /*
    for (int i = 0; i <= n - k; i++) {
        bool foundNegVal = false;

        for (int j = i; j < i + k; j++) {
            // cout << j << endl;
            if (A[j] < 0) {
                cout << A[j] << " ";
                foundNegVal = true;
                break;
            }
        }

        if (!foundNegVal) {
            cout << 0 << " ";
        }
    }
    */

    // O(nlog(n))
    // O(k)

    set<int> st;

    for (int i = 0; i < n; i++) {
        // add A[i] to the bucket
        // cout << A[i] << endl;
        if (A[i] < 0) st.insert(i);

        // remove first elem from the bucket
        if (i >= k) st.erase(i - k);

        debug(st);

        // update result
        if (i >= k - 1) {
            if (st.empty()) {
                cout << 0 << " ";
            } else {
                int index = *st.begin();
                cout << A[index] << " ";
            }
        }
    }
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