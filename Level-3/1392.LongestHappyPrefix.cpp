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
    const int MOD1 = 1e9 + 7;
    const int MOD2 = 1e9 + 7;

    vector<pair<int, int>> hashes, pow;

    MyHash(string s) {
        int n = s.size();
        hashes.assign(n + 1, {0, 0});
        pow.assign(n + 1, {1, 1});

        for (int i = 0; i < n; i++) {
            hashes[i + 1] = {
                (hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % MOD1,
                (hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % MOD2};

            pow[i + 1] = {
                (pow[i].first * BASE1) % MOD1,
                (pow[i].second * BASE2) % MOD2,
            };
        }
        // debug(hashes, hashes.size());
    }

    pair<int, int> get(int l, int r) {
        l++, r++;  // 1 based indexing
        // cout << l << " " << r << endl;
        int hash1 = (hashes[r].first - (hashes[l - 1].first * pow[r - l + 1].first) % MOD1 + MOD1) % MOD1;
        int hash2 = (hashes[r].second - (hashes[l - 1].second * pow[r - l + 1].second) % MOD2 + MOD2) % MOD2;

        return {hash1, hash2};
    }
};

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    MyHash myHash(s);
    string res = "";
    for (int i = n - 2; i >= 0; i--) {
        auto hashValue1 = myHash.get(0, i);
        auto hashValue2 = myHash.get(n - i - 1, n - 1);

        if (hashValue1 == hashValue2) {  // Can compare second has as well

            res = s.substr(0, i + 1);
            break;
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