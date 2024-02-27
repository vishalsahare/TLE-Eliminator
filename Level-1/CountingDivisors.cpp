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
    const int maxValue = 1e6 + 1;
    ll cnt[maxValue] = {0};
    for (int i = 1; i < maxValue; i++) {
        for (int j = i; j < maxValue; j+=i) {
            cnt[j]++;
        }
    }

    while (n--) {
        ll x; cin >> x;
        cout << cnt[x] << endl;
    }
    


// TLE

    // ll res = 0;
    // for (ll i = 1; i <= sqrt(n); i++) {
        
    //     if (n%i == 0) {
    //         res++;

    //         if(n/i != i) {
    //             res++;
    //         }
    //     }
    // }

    // cout << res;

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