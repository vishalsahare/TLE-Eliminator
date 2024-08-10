#ifndef ONLINE_JUDGE
#include "../debugger.hpp"
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
    int k;
    cin >> k;
    vector<pair<int, int> > nums;
    int x;

    for (int i = 0; i < k; i++) {
        int n;

        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> x;
            nums.push_back({x, i});
        }
    }

    sort(nums.begin(), nums.end());

    debug(nums, nums.size());

    int l = 0, r = 0;
    int n = nums.size();

    map<int, int> freq;
    vector<int> res;
    multiset<pair<int, int> > mst;
    while (r < n) {
        mst.insert({nums[r].second, r});

        // freq[nums[r].second]++;
        cout << l << " " << r << endl;

        if (r < n and mst.size() >= k) {
            cout << "====> " << l << " " << r << endl;
            cout << "====> " << nums[l].first << " " << nums[r].first << endl;

            if (res.empty() or (res[1] - res[0] > nums[r].first - nums[l].first)) {
                res.clear();
                res.push_back(nums[l].first);
                res.push_back(nums[r].first);
            }
            debug(mst);
            if (mst.begin()->first == nums[r].second) {
                mst.erase(mst.begin());

                debug(mst);
            }
            l++;
            cout << "[" << res[0] << "," << res[1] << "]" << endl;
        }

        r++;
    }

    // cout << "[" << res[0] << "," << res[1] << "]";
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