#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {

    string S; cin >> S;
    int chrCount[26] = {0};
    
    for (int i = 0; i < S.size(); i++) {
        chrCount[S[i]-'a']++;
    }

    string res = "";
    for (int i = 0; i < 26; i++) {
        char chr = i + 'a';
        while (chrCount[i] > 0) {
            res += chr;
            chrCount[i]--; 
        }
    }

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
        cout << endl;
    }

    return 0;
}