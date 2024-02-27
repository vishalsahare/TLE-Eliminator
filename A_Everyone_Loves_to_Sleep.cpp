#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {

    int n, H, M;
    cin >> n >> H >> M;

    int aH, aM;
    int res = INT_MAX-1;

    int sTime = H * 60 + M;

    for (int i = 0; i < n; i++) {
        cin >> aH >> aM;
        int aTime = aH * 60 + aM;
        int diff = aTime - sTime;

        if(diff < 0) {
            diff += 1440;   // 24 hour = 1440 minutes
        }

        res = min(res, diff);
    }

    cout << res / 60 << " " << res % 60;
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