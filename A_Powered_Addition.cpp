#ifndef ONLINE_JUDGE
#include "debugger.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

//------------

#define endl "\n"

//------------

void solve() {
    long long n;
    cin >> n;

    vector<long long> A(n, 0);

    for (long long i = 0; i < n; i++) {
        cin >> A[i];
    }

    long long maxSecondsRequired = -1;
    for (long long i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            // debug(A[i]);
            // debug(A[i - 1]);

            long long diff = A[i - 1] - A[i];
            long long hightestBitPos = (long long)(log2(diff));

            // debug(diff);
            // debug(hightestBitPos);

            maxSecondsRequired = max(maxSecondsRequired, hightestBitPos);
            A[i] = A[i - 1];

            // debug(A, n);
        }
    }

    if (maxSecondsRequired != -1) {
        cout << maxSecondsRequired + 1;
    } else {
        cout << 0;
    }
}

//------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./error.txt", "w", stderr);
    freopen("./output.txt", "w", stdout);
#endif

    long long t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}