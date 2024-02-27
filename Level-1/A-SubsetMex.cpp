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

    int cnt[101];
    memset(cnt, 0, sizeof(cnt));

    int x;
    for(int i = 0; i < n; i++) {

        cin >> x;
        cnt[x]++;
    }

    int a = 0, b = 0;
    for(int i = 0; i <= 101; i++) {

        if (cnt[i] > 0) {
            cnt[i]--;
        } else {
            a = i;
            break;
        }
    }
 
    for(int i = 0; i <= 101; i++) {

        if (cnt[i] > 0) {
            cnt[i]--;
        } else {
            b = i;
            break;
        }
    }

    cout << a + b;
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