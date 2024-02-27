#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

#define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

bool solve(ll i, ll N, ll X, ll value, int A[]) {
    
    if (i == N) {
        return value == X;
    }
    
    bool res1 = solve(i+1, N, X, value-A[i], A);
    bool res2 = solve(i+1, N, X, value+A[i], A);
    
    return res1 || res2;
}

/*=======================MAIN========================*/

int main()
{
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
        ll N, X; cin >> N >> X;
        int A[N];
        
        for (ll i = 0; i < N; i++) {
            cin >> A[i];
        }

        bool ans = solve(1, N, X, A[0], A);
        cout << (ans == true ? "YES" : "NO");
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}