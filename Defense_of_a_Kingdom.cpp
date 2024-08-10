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
    int w, h, n;
    cin >> w >> h >> n;

    if (n == 0) {
        cout << w * h;
        return;
    }

    vector<int> horizontal;
    vector<int> vertical;

    horizontal.push_back(0);
    vertical.push_back(0);

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        horizontal.push_back(x);
        vertical.push_back(y);
    }

    horizontal.push_back(w + 1);
    vertical.push_back(h + 1);

    sort(horizontal.begin(), horizontal.end());
    sort(vertical.begin(), vertical.end());

    int l = 0;
    for (int i = 1; i < horizontal.size(); i++) {
        int d = horizontal[i] - horizontal[i - 1] - 1;
        l = max(l, d);
    }

    int b = 0;
    for (int i = 1; i < vertical.size(); i++) {
        int d = vertical[i] - vertical[i - 1] - 1;
        b = max(b, d);
    }

    cout << l * b;
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