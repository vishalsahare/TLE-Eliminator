#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;


//------------
void solve() {

    ll x, y, z;
    cin >> x >> y >> z;

    ll eachWallCost = x * y * 2;

    int nWalls = 0;
    while (z - eachWallCost >= eachWallCost) {
        z -= eachWallCost;
        nWalls++;
    }
    cout << nWalls << endl;
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
        cout << "\n";
    }

    return 0;
}