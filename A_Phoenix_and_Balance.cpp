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
    uint n;
    cin >> n;

    uint sum1 = 1 << n;
    uint sum2 = 0;

    for (int i = 1; i < n / 2; i++) {
        sum1 += 1 << i;
    }

    for (int i = n / 2; i < n; i++) {
        sum2 += 1 << i;
    }

    cout << sum1 - sum2;
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