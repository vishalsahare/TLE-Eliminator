#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

#define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/
/*
w = [3, 4, 5]
v = [30, 50, 60]
*/

int solve(int i, int N, int W, int w[], int v[]) {

    if (i >= N) {
        return 0;
    }

    int picked = 0;
    int notPicked = 0;
    if (W-w[i] >= 0) {
        picked = v[i] + solve(i+1, N, W-w[i], w, v);
        notPicked = solve(i+1, N, W, w, v);
    } else {
        notPicked = solve(i+1, N, W, w, v);
    }
    
    return max(picked, notPicked);
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
        int N, W; cin >> N >> W;

        int w[N], v[N];
    
        for (int i = 0; i < N; i++) {
            cin >> w[i] >> v[i];
        }

        
        cout << solve(0, N, W, w, v);
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}