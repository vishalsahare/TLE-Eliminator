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
    string s;
    cin >> s;

    string even;
    string odd;

    for (auto chr : s) {
        if (chr % 2 == 1)
            odd += chr;
        else
            even += chr;
    }

    int p1 = 0, p2 = 0;
    string res;
    while (p1 < even.size() and p2 < odd.size()) {
        if (even[p1] - '0' < odd[p2] - '0') {
            res += even[p1];
            p1++;
        } else {
            res += odd[p2];
            p2++;
        }
    }

    while (p1 < even.size()) {
        res += even[p1];
        p1++;
    }

    while (p2 < odd.size()) {
        res += odd[p2];
        p2++;
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