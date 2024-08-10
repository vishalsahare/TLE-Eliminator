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
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int duplicate = 0;
    int minCost = c * n + d;  // [7 3 5 4 4 8]    Remove all and add 1

    set<int> st;

    for (int i = 0; i < n; i++) {
        if (st.find(A[i]) == st.end()) {
            st.insert(A[i]);
        } else {
            duplicate++;
        }

        int cost = 0;
        cost += duplicate * c;

        if (A[i] - ((i + 1) - duplicate) > 0) {
            cost += ((A[i] - ((i + 1) - duplicate)) * d);
        }

        cost += ((n - i - 1) * c);

        minCost = min(minCost, cost);
    }

    cout << minCost;
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
    cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}