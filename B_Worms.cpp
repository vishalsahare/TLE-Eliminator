#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------
void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> prefixSum(n);
    prefixSum[0] = A[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    int m;
    cin >> m;

    int val;
    for (int i = 0; i < m; i++) {
        cin >> val;
        int idx = 0;

        int L = 0;
        int R = n - 1;

        while (L <= R) {
            int mid = (L + R) / 2;

            if (prefixSum[mid] < val) {
                L = mid + 1;
            } else {
                idx = mid;
                R = mid - 1;
            }
        }
        cout << idx + 1 << endl;
    }
}

//------------
int main() {
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