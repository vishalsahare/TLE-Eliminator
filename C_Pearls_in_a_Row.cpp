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

    map<int, int> mp;

    int x;
    int start = 0;
    int end = 0;
    vector<pair<int, int> > segments;

    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x]++;
        if (mp[x] == 2) {
            segments.push_back({start + 1, end + 1});
            start = end + 1;
            end = start;
            mp.clear();
        } else {
            end++;
        }
    }

    if (segments.size() == 0) {
        cout << -1;
    } else {
        int lastSeg = segments.size();
        segments[lastSeg - 1].second = n;

        cout << segments.size() << endl;
        for (auto seg : segments) {
            cout << seg.first << " " << seg.second << endl;
        }
    }
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