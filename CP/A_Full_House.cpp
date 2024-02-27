#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;


//------------
void solve() {

    int A[14] = {0};
    int x;
    for (int i = 0; i < 5; i++) {
        cin >> x;
        A[x]++;
    }
    // cout << x << endl;
    int zeroElemsMoreThanTwo = 0;
    bool isElemsThree = false;
    bool isElemsTwo = false;
    for (int i = 0; i < 14; i++) {
        if (A[i] > 2) zeroElemsMoreThanTwo++;
        if (A[i] == 3) isElemsThree = true;
        if (A[i] == 2) isElemsTwo = true;
    }

    if (zeroElemsMoreThanTwo > 2) {
        cout << "No";
        return;
    }

    if (isElemsThree and isElemsTwo) {
        cout << "Yes";
        return;
    }

    cout << "No";

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