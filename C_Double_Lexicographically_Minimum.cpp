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
    string s;
    cin >> s;
    int n = s.size();

    sort(s.begin(), s.end());
    int l = 0;
    int r = n - 1;
    vector<char> res(n);

    for (int i = 0; i < n; i += 2) {
        if (i == n - 1) {
            res[l] = s[i];

        } else if (s[i] == s[i + 1]) {
            res[l] = s[i];
            res[r] = s[i + 1];
            l++;
            r--;

        } else if (s[i + 1] == s[n - 1]) {  // abbbbb => bbbabb
            int len = n - i - 1;
            int firstHalf = ceil(len / (2.0));
            int secondHalf = len / 2;
            while (firstHalf--) res[l++] = s[i + 1];
            res[l] = s[i];
            while (secondHalf--) res[r--] = s[i + 1];

            break;

        } else {  // cdefg  => cefgd
            for (int j = i + 1; j < n; j++) {
                res[l++] = s[j];
            }

            res[r] = s[i];
            break;
        }
    }

    // debug(res, n);
    for (auto chr : res) {
        cout << chr;
    }
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