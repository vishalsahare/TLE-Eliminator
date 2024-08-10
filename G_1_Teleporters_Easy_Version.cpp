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
    int n, c;
    cin >> n >> c;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i] += i + 1;
    }

    sort(A.begin(), A.end());

    int res = 0;
    int i = 0;

    while (i < n and c >= 0) {
        if (A[i] <= c) {
            c -= A[i];
            res++;
            i++;
        } else {
            break;
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
    cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}