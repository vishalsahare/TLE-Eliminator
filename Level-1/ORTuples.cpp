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

/*
A|B=P   B|C=Q   C|A=R

P   Q   R
---------
0   0   0   A=0 B=0 C=0 (1)
0   0   1   |                   this comb does not lead to any result.
0   1   0   |
0   1   1   A=0 B=0 C=1 (1)
1   0   0   |
1   0   1   A=1 B=0 C=0 (1)
1   1   0   A=0 B=1 C=0 (1)
1   1   1   A=1 B=1 C=1 (4)
            A=1 B=0 C=1
            A=0 B=1 C=1
            A=1 B=1 C=0
*/

void solve() {

    ll P, Q, R; cin >> P >> Q >> R;
    ll bitsCnt[20] = {0};

    ll res = 1;
    for (int i = 0; i < 20; i++) {
        int cnt = 0;
        if (P & 1<<i) cnt++;
        if (Q & 1<<i) cnt++;
        if (R & 1<<i) cnt++;

        if (cnt == 1) {
            cout << 0;
            return;
        }
        
        if (cnt == 3) {
            res *= 4;
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