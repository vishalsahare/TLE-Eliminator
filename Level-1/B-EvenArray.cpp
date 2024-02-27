#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

// #define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve() {

    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int nZeros = 0;
    int nOnes = 0;
    int fine = 0;
    for (int i = 0; i < n; i++) {
        if (i%2 == 0 and A[i]%2 == 1) {
            nZeros++;
        } else if(i%2 == 1 and A[i]%2 == 0) {
            nOnes++;
        } else {
            fine++;
        }
    }

    if (fine == n) {
        cout << 0;
    } else if (nZeros == nOnes) {
        cout << nOnes;
    } else {
        cout << -1;
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
    cin >> t;
    
    while (t--)
    {
        solve();
        cout << "\n";
    }

    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}