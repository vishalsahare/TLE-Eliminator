#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {

    int N, M; cin >> N >> M;
    map<int, int> noodleLenCount;
    int noodleLen;
    int x;

    for (int i = 0; i < N; i++) {
        cin >> noodleLen;
        noodleLenCount[noodleLen]++;
    }

    for (int i = 0; i < M; i++) {
        cin >> x;
        // cout << "--> " << noodleLenCount[x];
        if (noodleLenCount[x] == 0) {
            cout << "No";
            return;
        } 
        noodleLenCount[x]--;
    }

    // for(itr = noodleLenCount.begin(); itr != noodleLenCount.end(); itr++) {
    //     cout << itr->first << " " << itr->second << endl;
    // }

    cout << "Yes";
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