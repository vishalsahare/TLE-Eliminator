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
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    deque<long long> dq;
    long long alarmOFF = 0;

    for (int i = 0; i < n; i++) {
        long long x = A[i];
        dq.push_back(x);

        while (x >= dq.front() + m) {
            dq.pop_front();
        }

        while (dq.size() >= k) {
            dq.pop_back();
            alarmOFF++;
        }
    }

    cout << alarmOFF;
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