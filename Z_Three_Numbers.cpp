#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {

    int K, S; cin >> K >> S;

    int cnt = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
        
            int z = S - x - y;
            if(z >= 0 and z <= K) {
                cnt++;
            }
        }
    }
    cout << cnt;
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