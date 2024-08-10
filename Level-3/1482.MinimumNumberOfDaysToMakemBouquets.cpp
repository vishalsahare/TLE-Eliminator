#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define int int64_t

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------

bool predicateFun(int targetDay, vector<int> &bloomDays, int n, int k, int m) {
    int nBouquet = 0;
    int nFlower = 0;
    for (int i = 0; i < n; i++) {
        if (bloomDays[i] > targetDay) {  // cannt pick the flowers as its not bloomed
            nFlower = 0;
        } else {
            nFlower++;
            if (nFlower == k) {
                nBouquet++;
                nFlower = 0;
            }
        }

        if (nBouquet >= m) return true;
    }

    return false;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> bloomDays(n);

    for (int i = 0; i < n; i++) {
        cin >> bloomDays[i];
    }

    int L = 1, R = 1e9;

    int res = -1;
    while (L <= R) {
        int mid = (L + R) / 2;
        // cout << mid << endl;
        if (predicateFun(mid, bloomDays, n, k, m)) {
            res = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
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