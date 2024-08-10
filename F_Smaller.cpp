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

void solve() {
    int q;
    cin >> q;

    bool notA_T = false;
    bool notA_S = false;
    int countA_T = 0;
    int countA_S = 0;

    while (q--) {
        int d;
        int k;
        string x;

        cin >> d >> k;
        cin >> x;

        for (auto it : x) {
            if (it != 'a') {
                if (d == 2)
                    notA_T = true;
                else
                    notA_S = true;
                break;

            } else {
                if (d == 2) {
                    countA_T += k;
                } else {
                    countA_S += k;
                }
            }
        }

        if (notA_T == true)
            cout << "YES" << endl;
        else if (notA_S == true)
            cout << "NO" << endl;
        else if (countA_S < countA_T)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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
        // cout << endl;
    }

    return 0;
}