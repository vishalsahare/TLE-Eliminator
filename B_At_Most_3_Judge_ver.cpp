#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {

    int n, W; cin >> n >> W;
    int A[n];
    bool cnt[3000001];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < 3000001; i++) {
        cnt[i] = false;
    }

    for (int i = 0; i < n; i++) {
        cnt[A[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cnt[A[i] + A[j]] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                cnt[A[i] + A[j] + A[k]] = true;
            }
        }
    }

    ll nTotal = 0;
    for (int i = 1; i <=W ; i++) {
        if (cnt[i] == true)
            nTotal++;
    }
    cout << nTotal;
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