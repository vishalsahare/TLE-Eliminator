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
    string S;
    cin >> S;

    vector<int> TCount;
    vector<int> MCount;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'T') {
            TCount.push_back(i);
        } else if (S[i] == 'M') {
            MCount.push_back(i);
        }
    }

    bool res = true; 
    if (TCount.size() != MCount.size() * 2) {
        res = false;
    } else {
        int mSize = MCount.size();
        for (int i = 0; i < mSize; i++) {
            if (! (TCount[i] < MCount[i] and MCount[i] < TCount[i+mSize])) {
                res = false;
            }
        }
    }

    cout << ((res == true) ? "YES" : "NO");
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