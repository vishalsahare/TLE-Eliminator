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

struct MyHash {
    const int BASE1 = 5317;
    const int BASE2 = 8861;

    vector<pair<int, int>> hashes, pow;

    MyHash(string s) {
        int n = s.size();
        hashes.assign(n + 1, {0, 0});
        pow.assign(n + 1, {1, 1});

        for (int i = 0; i < n; i++) {
            hashes[i + 1] = {
                (hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % MOD,
                (hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % MOD};

            pow[i + 1] = {
                (pow[i].first * BASE1) % MOD,
                (pow[i].second * BASE2) % MOD,
            };
        }

        // debug(hashes, hashes.size());
    }

    pair<int, int> get(int l, int r) {
        l++, r++;  // 1 based indexing
        // cout << l << " " << r << endl;
        int hash1 = (hashes[r].first - (hashes[l - 1].first * pow[r - l + 1].first) % MOD + MOD) % MOD;
        int hash2 = (hashes[r].second - (hashes[l - 1].second * pow[r - l + 1].second) % MOD + MOD) % MOD;

        return {hash1, hash2};
    }
};

void solve_OrderOfn(string s) {
    // string s = "racecar";

    const int BASE1 = 5317;
    const int BASE2 = 8861;

    int n = s.size();
    vector<pair<int, int>> hashes(n + 1, {0, 0}), pow;

    debug(hashes, n);

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
        // solve_OrderOfn_2(s);
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