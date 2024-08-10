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
int mul(int x, int y) {
    return (x * y) % MOD;
}

int power(int x, int y) {
    int ans = 1;
    while (y > 0) {
        if (y & 1)
            ans = mul(ans, x);

        x = mul(x, y);
        y = y >> 1;
    }

    return ans;
}

int divide(int x, int y) {
    return mul(x, power(y, (MOD - 2)));
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    map<int, int> freq;
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        st.insert(A[i]);
        freq[A[i]]++;
    }

    int l = 0, r = 0;

    vector<int> distinct(st.begin(), st.end());
    int res = 0;
    int prod = 1;
    int len = distinct.size();
    for (l = 0; l < len; l++) {
        while (r < len and distinct[r] - distinct[l] < m) {
            prod = (prod * freq[distinct[r]]) % MOD;
            r++;
        }

        if (r - l == m) {
            res = (res + prod) % MOD;
        }

        prod = divide(prod, freq[distinct[l]]);
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