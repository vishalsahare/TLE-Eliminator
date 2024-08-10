#ifndef ONLINE_JUDGE
#include "../debugger.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

//------------

#define endl "\n"
#define int uint64_t

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // O(n*k)
    // O(1)
    /*
    for (int i = 0; i <= n - k; i++) {  // O(n-k-1)
        int maxVal = A[i];

        for (int j = i + 1; j < i + k; j++) {  // O(k)
            maxVal = max(maxVal, A[j]);
        }

        cout << maxVal << " ";
    }

    // O(nlog(k))
    /*
    vector<int> res;
    multiset<pair<int, int>> mst;

    // O(N)
    for (int i = 0; i < n; i++) {
        // add new elem in bucket
        mst.insert({A[i], i});  // O(log N)

        // remove first elem from the bucket
        if (i >= k) {
            if (mst. .find(A[i - k])->second == i) {
                mst.erase(mst.find(A[i - k]).first);  // O(log N)
            }
        }

        debug(mst);

        // update the res
        if (i >= k - 1) {
            int largest = *mst.rbegin();  // O(log N)
            res.push_back(largest);
        }
    }

    for (auto v : res) {
        cout << v << " ";
    }
    */
    // O(N)

    /*
    deque<pair<int, int>> dq;
    vector<int> res;

    for (int i = 0; i < n; i++) {
        // insert ith elem in bucket
        while (!dq.empty() && dq.back().first < A[i]) dq.pop_back();
        dq.push_back({A[i], i});

        // remove first elem from bucket
        if (i >= k && dq.front().second == i - k) dq.pop_front();

        // update res
        if (i >= k - 1)
            res.push_back(dq.front().first);
    }

    for (auto v : res) {
        cout << v << " ";
    }

    */
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