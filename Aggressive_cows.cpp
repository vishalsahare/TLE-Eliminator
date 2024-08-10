#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define int uint64_t

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------

bool isCowSafe(int d, vector<int> &A, int n, int c) {
    int cnt = 1;
    int prev = A[0];

    for (int i = 1; i < n; i++) {
        if (A[i] - prev >= d) {
            cnt++;
            prev = A[i];
        }
    }

    // cout << cnt << endl;
    return ((cnt >= c) ? true : false);
}

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int L = 1;
    int R = 1e12;

    // for (int i = 0; i < n; i++) {
    //     cout << A[i] << " ";
    // }

    // cout << endl;

    int res = 0;
    while (L <= R) {
        int mid = (L + R) / 2;
        // cout << L << " " << R << " " << mid << endl;

        if (isCowSafe(mid, A, n, c)) {
            res = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
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
    cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}