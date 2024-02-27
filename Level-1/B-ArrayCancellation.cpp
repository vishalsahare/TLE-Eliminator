#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {
    ll n; cin >> n;
    ll A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll res = 0;

    for (int i = 0; i < n; i++) {
        
        res += A[i];
        if (res < 0) {
            res = 0;
        }
    }

    cout << res;

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