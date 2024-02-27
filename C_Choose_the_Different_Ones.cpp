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

    int n, m, k; cin >> n >> m >> k;

    vector<int> A;
    vector<int> B;

    set<int> setA, setB;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        setA.insert(x);
    }

    for (int i = 0; i < m; i++) {
        cin >> x;
        setB.insert(x);
    }

    int aCount = 0;
    int bCount = 0;
    int commonCount = 0;

    for (int i = 1; i <= k; i++) {
        if (!setA.count(i) and !setB.count(i)) {
            cout << "NO";
            return;
        }

        if (setA.count(i) and setB.count(i)) {
            commonCount++;
        } else if (setA.count(i)) {
            aCount++;
        } else if (setB.count(i)) {
            bCount++;
        }
    }
    // cout << aCount << " " << bCount << " " << commonCount << endl;

    if (min(aCount, bCount) + commonCount < k/2) {
        cout << "No";
    } else if (aCount + bCount + commonCount == k) {
        cout << "YES";
    } else {
        cout << "NO";
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
        solve();
        cout << endl;
    }

    return 0;
}