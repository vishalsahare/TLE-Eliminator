#ifndef ONLINE_JUDGE
#include "../debugger.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

//------------

#define endl "\n"
#define uint long long
#define int int64_t

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------

void solve() {
    int n;
    cin >> n;

    vector<uint> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    // debug(A, n);

    uint median = 0;
    if (n & 1)
        median = A[n / 2];
    else
        median = (A[n / 2 - 1] + A[n / 2]) / 2;

    // debug(median);

    int res = 0;
    for (int i = 0; i < n; i++) {
        res += abs((median - A[i]));
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