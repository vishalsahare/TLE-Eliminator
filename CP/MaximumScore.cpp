#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

#define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve() {
    long long int n; cin >> n;
    long long int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = abs(res - A[i]);
    }
    cout << res;
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
    cin >> t;
    
    while (t--)
    {
        solve();
        cout << "\n";
    }

    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}