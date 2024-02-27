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

void primeFactors(vector<int> &primes, int num) {

    for (int i = 2; i*i <= num; i++) {

        if (num % i == 0) {
            primes.push_back(i);
            while(num%i == 0) {
                num /= i;
            }
        }
    }

    if (num != 1) {
        primes.push_back(num);
    }
}

void solve() {

    int n, m; cin >> n >> m;
    vector<int> A(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> coPrimes(100005, 1);

    // for (int i = 1; i <= m; i++) {
    //     cout << coPrimes[i] << " ";
    // }

    for (int i = 0; i < n; i++) {
        vector<int> primes;
        primeFactors(primes, A[i]);
        // cout << "size: " << primes.size() << endl;
        for (auto elem: primes) {
            // cout << "elem: " << elem << "coPrimes[elem]: " << coPrimes[elem] <<  endl;
            if (coPrimes[elem] == 1) {
                for (int j = elem; j <= m; j += elem) {
                    // cout << "j :" << j << endl;
                    coPrimes[j] = 0;
                }
            }
            // for (int i = 1; i <= m; i++) {
            //     cout << coPrimes[i] << " ";
            // }
        }
    }

    int nCoPrimes = 0;
    for (int i = 1; i <=m ; i++) {
        nCoPrimes += coPrimes[i];
    }

    cout << nCoPrimes << endl;    
    for (int i = 1; i <=m ; i++) {
        if (coPrimes[i])
            cout << i << endl;
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
    // cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}