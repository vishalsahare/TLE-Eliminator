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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    char maxPossibleChar = 'a';
    int maxPossibleCharIndex = -1;
    char notPossibleChar = 'a';
    int notPossibleCharIndex = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] - 'a' > k) {
            notPossibleChar = s[i];
            notPossibleCharIndex = i;
            break;
        }

        if (s[i] > maxPossibleChar) {
            maxPossibleChar = s[i];
            maxPossibleCharIndex = i;
        }
    }

    int opr = maxPossibleChar - 'a';
    k -= opr;
    char tillChar = notPossibleChar - k;

    for (char ch = notPossibleChar; ch > tillChar; ch--) {
        for (auto &t : s) {
            if (t == ch) {
                t--;
            }
        }
    }

    for (auto &t : s) {
        if (t <= maxPossibleChar)
            t = 'a';
    }

    cout << s;
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
    cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}