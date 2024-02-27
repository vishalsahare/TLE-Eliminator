#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {

    int n; cin >> n;
    int A[n][n];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            A[i][j] = s[j] - '0';
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << A[i][j];
    //     }
    //     cout << endl;
    // }

    int res = 0;

    int xLimit = n/2;
    int yLimit = n/2;
    if (n%2 == 1) {
        yLimit += 1;
    }
    for (int i = 0; i < xLimit; i++) {
        for (int j = 0; j < yLimit; j++) {
            
            int x = i;
            int y = j;
            int ones = A[x][y];

            x = j;
            y = n-i-1;
            ones += A[x][y];
            
            x = n-i-1;
            y = n-j-1;
            ones += A[x][y];
            
            x = n-j-1;
            y = i;
            ones += A[x][y];

            res += min(ones, 4-ones);
        }
    }
    cout << res;
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
    cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}