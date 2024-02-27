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
void solve(int N, vector<bool> &sieve, vector<int> &prefixSum) {

    for (int i = 2; i < N; i++) {
        if (!sieve[i]) {
            for (int j = 2*i; j < N; j += i) {
                sieve[j] = true;
            }
        }
    }

    for (int x = 1; x <= 5000; x++) {
        for (int y = 1; y <= 90; y++) {
            
            int primeForm = x*x + y*y*y*y;
            if (primeForm >= N) {
                break;
            }

            if (!sieve[primeForm]) {
                prefixSum[primeForm] = 1;
            }
        }        
    }

    for (int i = 1; i < N; i++) {
        prefixSum[i] += prefixSum[i-1];
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

    const int N = 10000007;
    vector<bool> sieve(N, false);
    vector<int> prefixSum(N, 0);

    solve(N, sieve, prefixSum);

    while (t--)
    {
        int n; cin >> n;
        cout << prefixSum[n];
        cout << endl;
    }

    return 0;
}