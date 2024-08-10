#ifndef ONLINE_JUDGE
#include "../debugger.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    debug(A, n);

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        // add kth number
        freq[A[i]] += 1;

        // remove first elem in k bucket
        if (i >= k) {
            freq[A[i - k]] -= 1;
            if (freq[A[i - k]] == 0) {
                freq.erase(A[i - k]);
            }
        }

        debug(freq);

        // update distinct elems in each bucket
        if (i >= k - 1) {
            cout << freq.size() << " ";
        }
    }
}

//------------
int main() {
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