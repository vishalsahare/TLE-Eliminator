#include <bits/stdc++.h>
using namespace std;
#include <numeric>

//------------
#define endl "\n"
#define int int64_t
const int MOD = 1e9 + 7;
//------------
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return (gcd(b, a % b));
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    // int L = 1;
    // int R = 1e9;

    int L = min(a, b);
    int R = n * max(a, b);

    int res = 0;
    while (L <= R) {
        int mid = (L + R) / 2;

        int cntDivisibleByA = mid / a;
        int cntDivisibleByB = mid / b;
        int lcm = (a * b) / gcd(a, b);
        int cntDivisibleByBoth = mid / lcm;
        int cnt = cntDivisibleByA + cntDivisibleByB - cntDivisibleByBoth;

        if (cnt < n) {
            L = mid + 1;
        } else if (cnt > n) {
            R = mid - 1;
        } else {  // cnt == n
            res = mid;
            R = mid - 1;
        }
    }

    cout << res % MOD;
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