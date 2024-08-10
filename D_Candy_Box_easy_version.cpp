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
    vector<int> freq;
    vector<int> A(n + 1);
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        A[x]++;
    }

    for (auto v : A) {
        if (v > 0)
            freq.push_back(v);
    }

    sort(freq.begin(), freq.end());

    int res = 0;
    int last = freq.back();
    int m = freq.size();
    for (int i = m - 1; i >= 0 and last > 0; i--) {
        if (freq[i] >= last) {
            res += last;
            last--;
        } else {
            res += freq[i];
            last = freq[i] - 1;
        }
    }

    // debug(freq, freq.size());

    cout << res;
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
    cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}