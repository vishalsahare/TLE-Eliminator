#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;


//------------
void solve() {

    int n; cin >> n;
    string s;
    char A[n][n];
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            A[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j];
        }
        cout << endl;
    }
    
    // int temp = A[0][0];

    // for (int i = 1; i < n; i++) {
    //     A[i-1][0] = A[i][0];
    // }
    // for (int j = 1; j < n; j++) {
    //     A[j-1][n-1] = A[j][n-1];
    // }
    // for (int i = n-1; i >=0 ; i--) {
    //     A[i][n-1] = A[i-1][n-1];
    // }
    // for (int j = n-1; j > 0 ; j--) {
    //     A[j][0] = A[j-1][0];
    // }
    // A[1][0] = temp;
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << A[i][j];
    //     }
    // }
}



//------------
int main() {
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
        cout << endl;
    }

    return 0;
}