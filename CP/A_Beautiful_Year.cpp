#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;


//------------
void solve() {

    int year; cin >> year;
    
    int res = 0;
    for (int y = year + 1; y < 10000; y++) {
        int A[10] = {0};
        int yr = y;
        bool foundRepeat = false;
        int q = 0;
        // cout << year << endl;
        while(yr > 0) {
            q = yr%10; 
            yr = yr/10;
            if (A[q] == 1) {
                foundRepeat = true;
                break;
            }
            A[q]++;
        }

        if (foundRepeat == false) {
            res = y;
            break;
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
    // cin >> t;

    while (t--)
    {
        solve();
        cout << "\n";
    }

    return 0;
}