#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {

    int H, W; cin >> H >> W;
    char A[H][W], B[H][W];
    string s;

    for (int i = 0; i < H; i++) {
        cin >> s;
        for (int j = 0; j < W; j++) {
            A[i][j] = s[j];
        }
    }

    for (int i = 0; i < H; i++) {
        cin >> s;
        for (int j = 0; j < W; j++) {
            B[i][j] = s[j];
        }
    }

    for (int s = 0; s < H; s++) {
        for (int t = 0; t < W; t++) {
        
            bool matched = true;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                
                    if (A[i][j] != B[(i+s)%H][(j+t)%W]) {
                        matched = false;
                        break;
                    }
                }
                if (!matched)
                    break;
            }

            if (matched) {
                cout << "Yes";
                return;
            }
        }
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
        cout << endl;
    }

    return 0;
}