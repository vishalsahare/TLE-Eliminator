#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

#define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

ll solve(ll n)
{
    if (n == 0 || n == 1) {
        return n;
    }

    if (n % 2 == 0) {
        return 1 + solve(n/2);
    } else {
        return 1 + solve(3*n+1);
    }
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
        ll a;
        cin >> a;
        ll res = solve(a);
        cout << res;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
