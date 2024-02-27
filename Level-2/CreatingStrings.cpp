#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

#define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/
vector<string> res;

void solve(map<char, int> &count, string outStr="") {

    if (count.empty()) {
        res.push_back(outStr);
        return;
    }

    for (auto [chr, cnt]: count) {
        if (cnt != 0) {
            auto n_count = count;
            if (--n_count[chr] == 0)
                n_count.erase(chr);
            
            solve(n_count, outStr + chr);
        }
    }
}


/*=======================MAIN========================*/

int main()
{
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
        string inStr; cin >> inStr;
        
        map<char, int> count;
        for (auto i: inStr) {
            count[i]++;
        }

        solve(count);
        cout << res.size() << endl;
        for (auto s: res) {
            cout << s << endl;
        }
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}