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
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }

    return a.first < b.first;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<uint, uint> > jobs(n);

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }

    sort(jobs.begin(), jobs.end(), compare);

    // debug(jobs, n);

    uint time = 0;
    bool canCompleteInTime = true;
    for (int i = 0; i < n; i++) {
        time += jobs[i].first;
        // debug(jobs[i]);
        // debug(time);

        if (time <= jobs[i].second) continue;

        canCompleteInTime = false;
        break;
    }

    cout << (canCompleteInTime == true ? "Yes" : "No");
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