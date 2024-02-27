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
void solve(int start, ll target, map<ll, ll> &res, set<ll>&comb, ll n) {

    if (target == 0) {
        res[comb.size()] = 1;
        // res.insert(comb);
        // set<ll >::iterator itr;
        // cout << "\nThe set s1 is : \n";
        // for (itr = comb.begin(); itr != comb.end(); itr++) {
        //     cout << *itr << " ";
        // }
        
        return;
    }

    for (int i = start; i < n; i+=2) {
        // cout << "i: " << i << "target-i: " << target-i << endl;
        if (i%2 != 0 and target-i >= 0) {
            comb.insert(i);
            solve(i+2, target-i, res, comb, n);
            comb.erase(i);
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
    cin >> t;

    while (t--)
    {
        ll target, n; cin >> n;
        map<ll, ll> res;
        set<ll> comb;
        target = n;
        // cout << "starting" << endl;
        solve(1, target, res, comb, n);
        int cnt = 0;

        cout << res.size();
        // // // cout << endl;

        // // for (int i = 0; i < res.size(); i++)
        // // {
        // //     if (res[i] > 0) {
        // //         cnt++;
        // //     }
        // // }
        
        // cout << cnt;
        cout << endl;
    }

    return 0;
}