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

    int n; cin >> n;

    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> st;
    int nbracket = 0;
    int nSquareBracket = 0;
    int depth = 0;

    int maxAltDepth = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == 1){ 
            st.push_back(A[i]);
        } else if (A[i] == 3) {
            st.push_back(A[i]);
        }
        
        if (A[i] == 2) {
            nbracket++;
            if (st.back() == 1) st.pop_back();
        } else if (A[i] == 4) {
            nSquareBracket++;
            if (st.back() == 3) st.pop_back();
        }

        if (st.size() == 0) {
            maxAltDepth++;
        }
    }

    cout << maxAltDepth << " " << nbracket*2 << " " << nSquareBracket*2;

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