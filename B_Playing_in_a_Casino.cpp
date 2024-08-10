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
void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll> > A(n, vector<ll>(m, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << A[i][j];
    //     }
    //     cout << endl;
    // }

    vector<ll> col[m];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            col[j].push_back(A[i][j]);
        }
    }

    /*

    1 4 2 8 5
    7 9 2 1 4
    3 8 5 3 1

    (0, 1)  total_winings = (7-1) + (9-4) + (2-2) + (8-1) + (5-4)
    (1, 2)  total_winings = (7-3) + (9-8) + (5-2) + (3-1) + (1-4)
    (0, 2)  total_winings = (3-1) + (8-4) + (5-2) + (8-3) + (5-1)

    137
    489
    225
    138
    145
    */

    ll res = 0;
    for (ll i = 0; i < m; i++) {
        sort(col[i].begin(), col[i].end());

        for (ll j = n - 1; j >= 0; j--) {
            res += j * col[i][j] - (n - 1 - j) * col[i][j];  // [1, 3 , 7]
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

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}