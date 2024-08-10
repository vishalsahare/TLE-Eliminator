#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << "'" << x << "'"; }
void __print(const char *x) { cerr << " << x << "; }
void __print(const string &x) { cerr << " << x << "; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << '}';
}
void _print() { cerr << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

//------------
/*
    n = 5
    1  2  3  4  5
    2  4  6  8 10
    3  6  9 12 15
    4  8 12 16 20
    5 10 15 20 25

                               13
    [1 2 2 3 3 4 4 4 5 5 6 6 8 8 9 10 10 12 12 15 15 16 20 20 25]
*/

bool predicateFunc(ll target, ll n) {
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += min(n, target / i);
    }

    // ll total = (n * n);
    // cout << target << " " << endl;

    // cout << ans << " " << total / 2 + 1 << endl;

    return (ans >= (n * n / 2 + 1) ? true : false);
}

void solve() {
    ll n;
    cin >> n;

    ll left = 0;
    ll right = (n * n);

    ll res = right;
    while (left <= right) {
        ll mid = (left + right) / 2;

        // cout << mid << endl;
        if (predicateFunc(mid, n)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << res;
}

//------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}