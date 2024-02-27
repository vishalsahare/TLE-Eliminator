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

    string a, b; cin >> a >> b;

    // cout << b << "sizeof b:" << sizeof(b) << endl;;

    string tmp = "";
    for (int i = 0; i < (a.size()-b.size()); i++) {
        tmp += '0';
    }

    b = tmp + b;

    // cout << tmp << endl;
    // cout << b << "sizeof b:" << sizeof(b) << endl;;
    int posOfOneB = 0;
    for (int i = b.size()-1; i >= 0; i--) {
        // cout << i << " ";
        if (b[i] == '1') {
            posOfOneB = i;
            break;
        }
    }

    // cout << "posOfOneB: " << posOfOneB << endl;
    // cout << a << "sizeof a:" << sizeof(a) << endl;;


    for (int i = a.size()-1; i >= 0; i--) {
        // cout << "i: " << i << endl;
        if (a[i] == '1' and i <= posOfOneB) {
            cout << posOfOneB-i;
            return;
        }
    }
    
    cout << 0;

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