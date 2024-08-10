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

    sort(A.begin(), A.end());

    if (A[0] != 1) {
        cout << 1;
        return;
    }

    // debug(A, n);
    long long minSum = 0;
    long long maxSum = 1;
    for (int i = 1; i < n; i++) {
        long long minNewSum = minSum + A[i];
        long long maxNewSum = maxSum + A[i];
        // debug(minSum, maxSum, minNewSum, maxNewSum);
        if (minNewSum - maxSum > 1) {
            break;
        }

        maxSum = maxNewSum;
        //(maxSum, maxNewSum);
    }

    cout << maxSum + 1;
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