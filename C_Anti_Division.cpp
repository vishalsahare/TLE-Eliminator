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

ll gcd(ll num1, ll num2) {
    if (num1 == 0) {
        return num2;
    }

    return gcd(num2%num1, num1);
}

ll lcm(ll c, ll d) {

    return (c * d)/gcd(c, d);
}

//------------
void solve() {

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll nCntDvdedByC = b/c - (a-1)/c;    // # of elems divided by c
    ll nCntDvdedByD = b/d - (a-1)/d;    // # of elems divided by d

    ll lcmCD = lcm(c, d);
    ll nCntDvdedByCD = b/lcmCD - (a-1)/lcmCD;   // # of elems divided by c and d

    ll totalElemsDivided = nCntDvdedByC + nCntDvdedByD - nCntDvdedByCD;

    ll totalRange = b-a+1;

    cout << totalRange - totalElemsDivided;  // # of elems not divided
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