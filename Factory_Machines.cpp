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

bool predict(ll targetTime, vector<ll> &time, ll n, ll targetProducts) {
    ll nProducts = 0;

    for (int i = 0; i < n; i++) {
        nProducts += targetTime / time[i];
        if (nProducts >= targetProducts) {
            return true;
        }
    }

    return (nProducts >= targetProducts);
}

void solve() {
    ll n, targetProducts;
    cin >> n >> targetProducts;

    ll left = 0;
    ll right = 1e18;

    vector<ll> time(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    ll res = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        // cout << mid << endl;
        if (predict(mid, time, n, targetProducts)) {
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
    freopen("../input.txt", "r", stdin);
    freopen("../error.txt", "w", stderr);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}