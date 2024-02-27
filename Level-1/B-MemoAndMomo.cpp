#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

#define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve()
{
    ll a, b, k;

    cin >> a >> b >> k;

    if (a%k == 0 && b%k == 0)
        cout << "Both";
    
    if (a%k == 0 && b%k != 0)
        cout << "Memo";
    
    if (a%k != 0 && b%k == 0)
        cout << "Momo";
    
    if (a%k != 0 && b%k != 0)
        cout << "No One";

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
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}