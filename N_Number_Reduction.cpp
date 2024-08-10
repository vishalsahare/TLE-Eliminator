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

    int k;
    cin >> k;

    if (k == 0) {
        cout << s;
        return;
    }

    int n = s.size();

    deque<int> nums[10];
    // debug(n);
    for (int i = 0; i < n; i++) {
        nums[s[i] - '0'].push_back(i);
    }

    string res;
    int i = 0;
    for (i = 0; i < n; i++) {
        // debug("=========");
        // debug(i);
        // debug(nums, 10);

        int cIndx = i;

        for (int j = (i == 0); j < 10; j++) {
            if (nums[j].size() and nums[j].front() - cIndx <= k) {
                res += ('0' + j);
                i = nums[j].front();
                break;
            }
        }

        // debug(nums, 10);

        k -= i - cIndx;

        // debug(i, k);

        for (int j = 0; j < 10; j++) {
            while (nums[j].size() and nums[j].front() <= i) {
                nums[j].pop_front();
            }
        }

        // debug(nums, 10);
        // debug(res);

        if (k == 0) {
            break;
        }
    }

    for (int j = i + 1; j < n; j++) {
        res += s[j];
    }

    cout << string(res.begin(), res.end() - k);
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