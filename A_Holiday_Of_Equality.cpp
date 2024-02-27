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
    int maxBurles = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        maxBurles = max(maxBurles, A[i]);
    }

    ll nTotal = 0;
    for (int i = 0; i < n; i++) {
        nTotal += maxBurles - A[i];
    }

    cout << nTotal;
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

    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}