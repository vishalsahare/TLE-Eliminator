#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

// #define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve()
{
    int r, c;
    cin >> r >> c;

    int A[r][c], B[r][c];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> A[i][j];
        }
    }
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << endl;
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
        solve();
        cout << "\n";
    }

    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}