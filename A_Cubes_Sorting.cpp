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
    int n;
    cin >> n;

    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    /*
        5 4 3 2 1 => n(n-1)/2 or more
        decreasing and unique

        No => if swap need to be great or equal to n(n-1)/2 mean decreasing and unique
        Yes => less than n(n-1)/2 always since non unique or non monotonous decreasing in nature
                hence requires less than n(n-1)/2 swaps

    */
    bool flag = false;
    // cout << n;
    for (int i = 1; i < n; i++) {
        if (A[i - 1] <= A[i]) {
            flag = true;
        }
    }

    cout << (flag == true ? "YES" : "NO");
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