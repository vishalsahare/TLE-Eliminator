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

const int BASE = 5317;

int myHash(string s) {
    int hashValue = 0;

    int n = s.size();

    for (int i = 0; i < n; i++) {
        hashValue = (hashValue * BASE + (s[i] - 'a' + 1)) % MOD;
    }

    return hashValue;
}

void solve_OrderOfn_3(string s) {
    // string s = "racecar";

    int n = s.size();
    vector<vector<int>> hashes(n, vector<int>(n));

    debug(hashes, n);

    // O(nˆ3)

    for (int i = 0; i < n; i++) {  // O(nˆ2)
        for (int j = i; j < n; j++) {
            hashes[i][j] = myHash(s.substr(i, j - i + 1));  // O(n)
        }
    }

    debug(hashes, n);
}

void solve_OrderOfn_2(string s) {
    // string s = "racecar";
    int n = s.size();
    vector<vector<int>> hashes(n, vector<int>(n));

    debug(hashes, n);

    // O(nˆ2)

    for (int i = 0; i < n; i++) {  // O(n)
        int hash = 0;
        for (int j = i; j < n; j++) {  // O(n)
            hash = (hash * BASE + (s[j] - 'a' + 1)) % MOD;

            hashes[i][j] = hash;
        }
    }

    debug(hashes, n);
}

void solve() {
    string s = "racecar";

    void solve_OrderOfn(string s) {
        solve_OrderOfn_2(s);
        // solve_OrderOfn_3(s);
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