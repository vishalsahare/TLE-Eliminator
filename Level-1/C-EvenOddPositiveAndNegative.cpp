#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

// #define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve() {
    
    int n, x;
    cin >> n;

    int evenCount = 0;
    int oddCount = 0;
    int pTive = 0;
    int nTive = 0;

    while (n--) {
        cin >> x;

        if (x % 2 == 0)
            evenCount++;
        else
            oddCount++;
        
        if (x > 0)
            pTive++;
        else if(x < 0)
            nTive++;
    }
    
    cout << "Even: " << evenCount << endl;
    cout << "Odd: " << oddCount << endl;
    cout << "Positive: " << pTive << endl;
    cout << "Negative: " << nTive << endl;
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