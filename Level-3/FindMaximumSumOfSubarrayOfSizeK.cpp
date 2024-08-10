#ifndef ONLINE_JUDGE
#include "../debugger.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

//------------
#define endl "\n"
#define ll long long int

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

    // Complexity
    // O(n*k)
    // O(1)

    /*
    int res = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < i + k; j++) {
            sum += A[j];
        }

        res = max(res, sum);
    }

    cout << res;
    */

    // Complexity: Time Optimization
    // O(n)
    // O(k)

    /*
    int res = 0;
    int sum = 0;

    queue<int> q;

    for (int i = 0; i < n; i++) {
        // add new elem to window
        q.push(A[i]);
        sum += A[i];

        // remove 1st elem from window
        if (i >= k) {
            sum -= q.front();
            q.pop();
        }

        debug(q);

        // update the result
        if (i >= k - 1) {
            res = max(res, sum);
        }
    }

    cout << res;
    */

    // Space Optimization
    // O(n)
    // O(1)

    int sum = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        // add new element to window
        sum += A[i];

        // remove 1st element from the window
        if (i >= k) {
            sum -= A[i - k];
        }
        // update the max sum once i crosses k-1
        if (i >= k - 1) {
            res = max(res, sum);
        }
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
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}