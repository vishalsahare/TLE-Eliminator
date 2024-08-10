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
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    vector<int> freq(m + 1);
    vector<int> uselessIndices;

    for (int i = 0; i < n; i++) {
        cin >> A[i];

        if (A[i] > m) {
            uselessIndices.push_back(i);
        } else if (freq[A[i]] == n / m) {
            uselessIndices.push_back(i);
        } else {
            freq[A[i]]++;
        }
    }

    int maximizedMin = n / m;
    int cnt = 0;

    for (int i = 1; i <= m; i++) {
        while (freq[i] < maximizedMin) {
            int index = uselessIndices.back();
            uselessIndices.pop_back();
            A[index] = i;
            cnt++;
            freq[i]++;
        }
    }

    cout << maximizedMin << " " << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
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
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}