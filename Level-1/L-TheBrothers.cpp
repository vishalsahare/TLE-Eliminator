#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

#define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve()
{
    string F1, S1;
    string F2, S2;
    cin >> F1 >> S1;
    cin >> F2 >> S2;

    cout << ((S1 == S2) ? "ARE Brothers" : "NOT");
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