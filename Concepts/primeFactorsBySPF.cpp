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

vector<pair<uint, uint>> primeFactors(uint x, vector<uint> &spf) {
    vector<pair<uint, uint>> res;

    while (x != 1) {
        int prime = spf[x];
        int count = 0;

        while (x % prime == 0) {
            count++;
            x /= prime;
        }

        res.push_back({prime, count});
    }

    return res;
}

void solve() {
    uint n;
    cin >> n;

    vector<bool> isPrime(1e6, true);
    isPrime[0] = false;
    isPrime[1] = false;

    vector<uint> spf(1e6, 1e9);

    for (int i = 0; i < n; i++) {
        spf[i] = i;
    }

    for (uint i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
                spf[j] = min(spf[j], i);
            }
        }
    }

    // debug(isPrime, n + 1);
    debug(spf, n + 1);
    vector<pair<uint, uint>> res = primeFactors(n, spf);
    debug(res, res.size());
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