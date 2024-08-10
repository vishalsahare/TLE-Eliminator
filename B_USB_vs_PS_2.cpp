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
    int a, b, c;
    cin >> a >> b >> c;

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> usbPQ, psPQ;

    int x;
    string type;
    for (int i = 0; i < n; i++) {
        cin >> x >> type;

        if (type == "USB")
            usbPQ.push(x);
        else
            psPQ.push(x);
    }

    int nComp = 0;
    int res = 0;
    while (a > 0 and !usbPQ.empty()) {
        res += usbPQ.top();
        usbPQ.pop();
        a--;
        nComp++;
    }

    while (b > 0 and !psPQ.empty()) {
        res += psPQ.top();
        psPQ.pop();
        b--;
        nComp++;
    }

    while (!psPQ.empty()) {
        usbPQ.push(psPQ.top());
        psPQ.pop();
    }

    while (c > 0 and !usbPQ.empty()) {
        res += usbPQ.top();
        usbPQ.pop();
        c--;
        nComp++;
    }

    cout << nComp << " " << res;
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