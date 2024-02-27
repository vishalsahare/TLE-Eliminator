#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

// #define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

int solve(int i, int j, int r, int c, vector<vector<int> > &A)
{
    if (i == r - 1 and j == c - 1) {
        return A[i][j];
    }

    if (i >= r or j >= c) {
        return 0;
    }

    int right = A[i][j] + solve(i+1, j, r, c, A);
    
    int down = A[i][j] + solve(i, j+1, r, c, A);

    return max(right, down);
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
        int r, c;
        cin >> r >> c;
        vector<vector<int> > A(r, vector<int>(c));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {

                cin >> A[i][j];
            }
        }
        
        cout << solve(0, 0, r, c, A) << endl;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}