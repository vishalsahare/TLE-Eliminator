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
ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    
    return gcd(b%a, a);
}

ll lcm(ll a, ll b) {
    return (a*b)/gcd(a, b);
}

void solve() {

    ll n; cin >> n;
    vector<ll> divisors;

    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            divisors.push_back(i);
            if (n/i != i) {
                divisors.push_back(n/i);
            }
        }
    }

    // cout << "n :" << n << endl;
    // for (int i = 0; i < divisors.size(); i++) {
    //     cout << divisors[i] << " ";
    // }

    ll a = 1;
    ll b = n-1;
    ll res = lcm (a, b);
    // cout << "res : " << res << endl;
    for(auto elem: divisors) {
        // cout << elem << endl;
        ll tmpA = elem;
        ll tmpB = n - elem;
        // cout << tmpA << " " << tmpB << endl;
        ll tmpRes = lcm(tmpA, tmpB);
        // cout << tmpRes << endl;
        if (tmpRes < res) {
            res = tmpRes;
            a = tmpA;
            b = tmpB;
        }
    }

    cout << a << " " << b;

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