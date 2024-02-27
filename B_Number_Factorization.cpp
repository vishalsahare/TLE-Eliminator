#include <bits/stdc++.h>
using namespace std;


//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << "'" << x << "'";}
void __print(const char *x) {cerr << " << x << ";}
void __print(const string &x) {cerr << " << x << ";}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << '}';}
void _print() {cerr << "\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//------------
void solve() {

    ll n; cin >> n;

    map<ll, ll> primeNumCount;

    ll maxPower = 1;
    for (ll i = 2; i*i <= n; i++) {
    
        ll cnt = 0;
        if (n%i == 0) {
            while (n%i == 0) {
                n /= i;
                cnt++;
            }
            
            primeNumCount[i] = cnt;
            maxPower = max(maxPower, cnt);
        }
    }

    if (n > 1) {
        primeNumCount[n] = 1;
    }

    // cout << primeNumCount.size() << endl;

    ll res = 0;
    for(ll i = 1; i <= maxPower; i++) {

        ll product = 1;
        for (auto it = primeNumCount.begin(); it != primeNumCount.end(); it++) {
            // cout << it->first << " " << primeNumCount[it->second] << endl;
            if (it->second > 0) {
                product *= it->first;
                primeNumCount[it->first]--;
            }
        }
        res += product;
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