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

ll rSolve(ll i, ll j, ll n, ll k) {
    if (i > n or j > k) {
        return 0;
    }

    
}
void solve() {

    ll n, k;
    cin >> n >> k;

    // number of good sequence such that jth number divides j-1th number at ith length
    vector<ll, ll> dp(k+1, vector<ll> (n+1));

    ll res = rSolve(1, 1, n, k);

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