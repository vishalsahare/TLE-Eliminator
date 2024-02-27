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
    int x;

    vector<pair<int, int> > mapBuildInd;

    for (int i = 0; i < n; i++) {
        cin >> x;
        mapBuildInd.push_back(make_pair(x, i));
    }

    vector<int> res(n);
    sort(mapBuildInd.begin(), mapBuildInd.end());

    ll curr = 1;
    ll minTime = 0;
    for (int i = n-1; i >= 0; i--) {
        res[mapBuildInd[i].second] = curr;
        minTime += 2 * abs(0 - mapBuildInd[i].first) * abs(curr);
        if (curr > 0) {
            curr *= -1;
        } else {
            curr *= -1;
            curr += 1;
        }
    }

    cout << minTime << endl;
    cout << 0 << " ";
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
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