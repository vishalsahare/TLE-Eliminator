#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

// #define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve() {

	int n;
    cin >> n;

	int counter = 1;
	for (int i = 0; i < n; i++) {
		int A[i+1];
		for (int j = 0; j <= i; j++) {
			A[j] = counter++;
		}

		if (i%2 == 0) {
			reverse(A, A+i+1);
		}

        for (int k = 0; k <= i; k++) {
            cout << A[k] << " ";
        }
        cout << endl;
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
        solve();
        cout << "\n";
    }

    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}