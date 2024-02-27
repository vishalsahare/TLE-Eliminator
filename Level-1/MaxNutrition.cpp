#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

// #define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

int solve(int i, int prev, std::vector<int>&type, std::vector<int>&nutrition) {
    
    if (i >= type.size()) {
        return 0;
    }

        int res = 0;
        int currMaxNut = 0;
        if (type[i] == prev or prev == -1) {
            while (i < type.size() and type[i] == type[i+1]) {
                currMaxNut = max(currMaxNut, nutrition[i]);
                i++;
            }
            if (prev == -1) {
                res = nutrition[i] + solve(i+1, i, type, nutrition);
            } else {
                res = currMaxNut + solve(i+1, i, type, nutrition);
            }

        } else {
            if (nutrition[i] > 0) {
                res = nutrition[i] + solve(i+1, i, type, nutrition);
            }
        }

    return res;
    
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
    cin >> t;
    
    std::vector<int> type;
    std::vector<int> nutrition;
    int data;
    int elems;
    while (t--)
    {
        cin >> elems;
        for(int i = 0; i < elems; i++) {
            cin >> data;
            type.push_back(data);
        }
        for(int i = 0; i < elems; i++) {
            cin >> data;
            nutrition.push_back(data);
        }

        cout << solve(0, -1, type, nutrition);
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}