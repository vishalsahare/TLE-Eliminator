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
    int prev =0;
    int x = 0;

    vector<int> lst;
    cin >> x;
    for (int i = 0; i < n-1; i++) {
        prev = x;
        cin >> x;
        
        if (prev < x) {
            int diff = x-prev;
            for (int j = 0; j < diff; j++) {
                lst.push_back(prev + j);
            }
        } else {
            // int diff = prev-x;
            for (int j = prev; j > x; j--) {
                lst.push_back(j);
            }
        }
    }

    lst.push_back(x);

    for (int i = 0; i < lst.size(); i++) {
        cout << lst[i] << " ";
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
    // cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}