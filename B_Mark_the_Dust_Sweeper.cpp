#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {

    int n; cin >> n;
    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Logic is res = sum of all non leading zeros + sum of all n-1 terms
    ll nOps = 0;
    int leadZeroIdx = 0;
    while (leadZeroIdx < n and A[leadZeroIdx] == 0) {
        leadZeroIdx++;
    }

    for (int i = leadZeroIdx; i < n-1; i++) {
        nOps += A[i];
        if (A[i] == 0)
            nOps++;
    }

    cout << nOps;
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
    cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}