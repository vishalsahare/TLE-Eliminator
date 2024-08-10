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

void solve() {
    string s, t;
    cin >> s;
    cin >> t;

    MyHash sHash(s);
    // sHash = MyHash(s);
    // tHash = MyHash(t);
    MyHash tHash(t);

    auto tHashValue = tHash.get(0, t.size() - 1);

    // cout << tHashValue.first << " " << tHashValue.second << endl;
    // int nt = t.size();
    int res = 0;
    for (int i = 0; i + t.size() - 1 < s.size(); i++) {
        auto sHashValue = sHash.get(i, i + t.size() - 1);
        // cout << sHashValue.first << " " << sHashValue.second << endl;
        if (sHashValue.first == tHashValue.first and sHashValue.second == tHashValue.second) {
            res++;
        }
    }

    cout << res;
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