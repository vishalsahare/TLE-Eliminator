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

    map<ll, ll> freqOfPrimeNums;

    for (ll num = 1; num <= n; num++ ) {
        ll copyN = num;

        while (copyN%2 == 0) {
            freqOfPrimeNums[2]++;
            copyN /= 2;
            
        }
        for (ll i = 3; i*i <= copyN; i+=2) {
            
            while (copyN%i == 0) {
                freqOfPrimeNums[i]++;
                copyN /= i;
            }
        }

        if (copyN > 1) {
            freqOfPrimeNums[copyN]++;
        }
    }

    /*
        N = p^a         =>  (a+1)
            1, p^1, p^2, p^3, ..... , p^a => a+1
        
        n = p^a q^b     =>  (a+1) * (q+1)
            1   p^1     p^2, p^3, ..... , p^a => a+1
            q   p^1q^1  .    .  .   .   .   .   
            q^1 .
            q^2 .
            .
            .
            q^b .       .   .   .   .   . p^a q^b

            q+1

        n = p^a q^b r^c =>  (a+1) * (q+1) * (c+1)
    */

    ll divisors = 1;
    for (auto elem: freqOfPrimeNums) {
        divisors = ((divisors % MOD) * (elem.second + 1) % MOD) % MOD;
    }

    cout << divisors;
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