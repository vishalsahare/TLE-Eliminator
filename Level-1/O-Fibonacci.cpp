#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

// #define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve() {

    int n; cin >> n;

    int fib[n];
    fib[0] = 0;

    if (n != 1)
        fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    cout << fib[n-1];
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
        solve();
        // cout << "\n";
    }

    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}