#ifndef ONLINE_JUDGE
#include "debugger.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

//------------

#define endl "\n"
#define uint uint64_t
#define int int64_t

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------

void solve() {
    int n, p;
    cin >> n >> p;

    vector<int> A(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        total += A[i];
    }

    int nTimeSongsList = 0;
    if (total < p) {
        nTimeSongsList += p / total;
        p %= total;
    }

    int l = 0, r = 0;
    int nSongs = INT_MAX;
    int startSong = -1;

    while (l < n) {
        int r = l;
        int sum = 0;
        int songHeard = 0;
        while (sum < p) {
            sum += A[r];
            songHeard++;
            r = (r + 1) % n;
        }

        if (songHeard < nSongs) {
            nSongs = songHeard;
            startSong = l;
        }

        l++;
    }

    cout << startSong + 1 << " " << nSongs + nTimeSongsList * n;
}

//------------
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../error.txt", "w", stderr);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}