#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

// #define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve() {

    int n, t;
    cin >> n >> t;

    string S;
    cin >> S;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n-1; j++) {
            if (S[j] == 'B' and S[j+1] == 'G') {
                char tmp = S[j];
                S[j] = S[j+1];
                S[j+1] = tmp;
                j++;
            }
        }
    }

    cout << S;
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