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

    bool foundNegVal = false;

    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (sum <= 0) {
            cout << "NO";
            return;
        }
    }

    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += A[i];
        if (sum <= 0) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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