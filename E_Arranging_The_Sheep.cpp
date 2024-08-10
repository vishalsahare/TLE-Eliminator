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

    string s;
    cin >> s;

    int minI = INT_MAX;
    int maxI = INT_MIN;

    int i = 0;
    int count = 0;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            v.push_back(i);
        }
    }

    // debug(s);
    // debug(v, v.size());

    int median = 0;
    int m = v.size();
    if (m == 0) {
        cout << 0;
        return;
    }

    median = v[m / 2];
    int cnt = 0;
    int res = 0;

    for (int i = median - 1; i >= 0; i--) {
        if (s[i] == '.') {
            ++cnt;
        } else {
            res += cnt;
        }
    }

    cnt = 0;
    for (int i = median + 1; i < n; i++) {
        if (s[i] == '.') {
            ++cnt;
        } else {
            res += cnt;
        }
    }

    // debug(res);

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