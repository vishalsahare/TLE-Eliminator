#ifndef ONLINE_JUDGE
#include "debugger.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

//------------
#define endl "\n"
#define ll long long

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------
vector<vector<int>> dp(5001, vector<int>(5001, -1));

int rSolve(int i, int j, string s1, string s2) {
    if (i == s1.size()) {
        return s2.size() - j;
    }

    if (j == s2.size()) {
        return s1.size() - i;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (s1[i] == s2[j]) {
        return dp[i][j] = rSolve(i + 1, j + 1, s1, s2);
    } else {
        int add = 1 + rSolve(i, j + 1, s1, s2);

        int remove = 1 + rSolve(i + 1, j, s1, s2);

        int replace = 1 + rSolve(i + 1, j + 1, s1, s2);

        return dp[i][j] = min({add, remove, replace});
    }

    return -1;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // int res = rSolve(0, 0, s1, s2);
    // cout << res;

    // Iteractive no of operations to get s1 to s2 from i, j to n,
    vector<vector<int>> idp(n + 1, vector<int>(m + 1, 1e6));

    for (int i = 0; i <= n; i++) {
        idp[i][0] = i;
    }

    for (int j = 0; j <= m; j++) {
        idp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                idp[i][j] = idp[i - 1][j - 1];
            } else {
                int replace = idp[i - 1][j - 1] + 1;

                int add = idp[i][j - 1] + 1;

                int del = idp[i - 1][j] + 1;

                idp[i][j] = min({idp[i][j], replace, add, del});
            }
        }
    }

    cout << idp[n][m];
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
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}