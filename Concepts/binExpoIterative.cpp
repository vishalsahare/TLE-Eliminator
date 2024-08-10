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

uint binPow(uint a, uint b) {
    uint res = 1;

    debug(a, b);
    while (b > 0) {
        if (b & 1)
            res = res * a;

        a = a * a;
        b = b >> 1;

        debug(res, a, b);
    }

    return res;
}

void solve() {
    uint a, b;
    cin >> a >> b;

    cout << binPow(a, b);
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