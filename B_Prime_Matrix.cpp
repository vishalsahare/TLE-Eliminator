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
void solve(int N, vector<bool> &sieve, vector<int> &primes) {

    int n, m; cin >> n >> m;
    int A[n][m];
    // cout << n << " " << m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    
    // for (int i = 0; i < primes.size(); i++) {
    //     cout << primes[i] << " ";
    // }
    

    int res = INT_MAX;
    for (int i = 0; i < n; i++) {

        int count = 0;
        for (int j = 0; j < m; j++) {
            int nearestPrime = (*lower_bound(primes.begin(), primes.end(), A[i][j]));
            count += nearestPrime - A[i][j];
        }
        res = min(res, count);
    }

    for (int i = 0; i < m; i++) {
        
        int count = 0;
        for (int j = 0; j < n; j++) {
            int nearestPrime = (*lower_bound(primes.begin(), primes.end(), A[j][i]));
            count += nearestPrime - A[j][i];
        }
        res = min(res, count);
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
    int N = 100005;
    vector<bool> sieve(N, true);
    vector<int> primes;

    for (int i = 2; i <= N; i++) {
        if(sieve[i]) {
            for (int j = 2*i; j <= N; j+=i) {
                sieve[j] = false;
            }
        }
    }

    for (int i = 2; i <=N ; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }

    while (t--)
    {
        solve(N, sieve, primes);
        cout << endl;
    }

    return 0;
}