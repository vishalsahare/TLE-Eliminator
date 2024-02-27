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

    string res = "";
    if (n >= 60) {
        res = to_string(21 + 1);
        n = n%60;
    } else {
        res = to_string(21);
    }
    res += ":";
    res += (n <= 9 ? "0" + to_string(n) : to_string(n));

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