#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------
#define mod 1000000007

// #define ll long long int

//-------------------------------------------------

/***********************SOLVE**********************/

void solve() {
    
	int num;
	cin >> num;    //Reading input from STDIN
	// cout << "Input number is " << num << endl;	// Writing output to STDOUT

	for (int i = 0; i < num; i++) {
		if (i == 0) {
			for (int j = 0; j < num; j++) {
				cout << "*";
			}
			cout << endl;
		}

/*
        *****      i
           *    3  1
          *     2  2
         *      1  3
        *****
*/
		if (i > 0 and i < num-1) {
			int j = 0;
			for (; j < num - i - 1; j++) {
				cout << " ";
			}
			cout << "*";
			for (; j < num; j++) {
				cout << " ";
			}
            cout << endl;
		}

		if (i == num-1) {
			for (int j = 0; j < num; j++) {
				cout << "*";
			}
			cout << endl;
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
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}