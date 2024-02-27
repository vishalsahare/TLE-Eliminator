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

    ll xDir = 0, yDir = 0;
    char dir = 'E';

    for (int i = 0; i < n; i++) {
        if (S[i] == 'S') {
            switch (dir)
            {
                case 'E':
                    xDir+=1; break;
                case 'W':
                    xDir-=1; break;
                case 'N':
                    yDir+=1; break;
                case 'S':
                    yDir-=1; break;            
            }        
        } else {

            switch(dir) {
                case 'E':
                    dir = 'S'; break;
                case 'W':
                    dir = 'N'; break;
                case 'N':
                    dir = 'E'; break;
                case 'S':
                    dir = 'W'; break;            
            }
        }
    }

    cout << xDir << " " << yDir;
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