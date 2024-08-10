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

int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    int sum1 = 0;
    int sum2 = 0;
    int n = nums1.size();
    vector<int> d(n);

    for (int i = 0; i < n; i++) {
        d[i] = nums2[i] - nums1[i];
        sum1 += nums1[i];
        sum2 += nums2[i];
    }

    int res = max(sum1, sum2);

    // Kedene's Algo
    int maxSum = 0;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += d[i];
        maxSum = max(maxSum, currSum);

        if (currSum > 0) {
            res = max(res, sum1 + maxSum);
        } else {
            currSum = 0;
        }
    }

    for (auto& it : d) {
        it *= -1;
    }

    maxSum = 0;
    currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += d[i];
        maxSum = max(maxSum, currSum);

        if (currSum > 0) {
            res = max(res, sum2 + maxSum);
        } else {
            currSum = 0;
        }
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << maximumsSplicedArray(nums1, nums2);
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