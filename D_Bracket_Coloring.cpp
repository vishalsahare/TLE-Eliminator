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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sum1 = 0;
    int sum2 = 0;
    int color1 = 0;
    int color2 = 0;

    int color = 0;
    vector<int> colors(n, 0);

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (sum2 > 0) {
                sum2--;
                // if (color2 == 0) {
                //     color2 == color++;
                // }
                colors[i] = color2;
            } else {
                sum1++;
                if (color1 == 0) {
                    color1 = ++color;
                }
                colors[i] = color1;
            }
        } else {
            if (sum1 > 0) {
                sum1--;
                // if (color1 == 0) {
                //     color1 == color++;
                // }
                colors[i] = color1;
            } else {
                sum2++;
                if (color2 == 0) {
                    color2 = ++color;
                }
                colors[i] = color2;
            }
        }
    }

    if (sum1 + sum2 > 0) {
        cout << -1;
        return;
    }

    if (color1 > 0 and color2 > 0) {
        cout << 2 << endl;
    } else if (color1 > 0 or color2 > 0) {
        cout << 1 << endl;
    }

    for (auto color : colors) {
        cout << color << " ";
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
        cout << endl;
    }

    return 0;
}