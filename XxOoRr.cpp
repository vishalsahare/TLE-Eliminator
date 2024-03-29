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

    int n, k; cin >> n >> k;

    int numBitsCount[32] = {0};
    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // for (int i = 0; i < n; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < 32; i++)
    {  
        int nElemAtIthPos = 0;
        for (int j = 0; j < n; j++) {
            // cout << A[j] << endl;
            if ((A[j] & (1 << i)) > 0) {
                nElemAtIthPos++;
            }
        }
        // cout << "nElemAtIthPos: " << nElemAtIthPos << endl;
        numBitsCount[i] = nElemAtIthPos;
    }

    // for (int i = 31; i >= 0; i--)
    // {
    //     cout << numBitsCount[i] << " ";
    // }
    // cout << endl;

    int ops = 0;
    for (int i = 0; i < 32; i++) {
        if (numBitsCount[i] > 0)
            ops += ceil(numBitsCount[i]/(float)k);
    }
    
    cout << ops;
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