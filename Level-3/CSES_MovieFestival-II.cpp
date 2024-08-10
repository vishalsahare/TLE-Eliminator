#ifndef ONLINE_JUDGE
#include "../debugger.hpp"
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
struct Movie {
    int start;
    int end;
    int index;
};

template <class T>
bool funCmp(T a, T b) {
    if (a.end != b.end)
        return a.end < b.end;

    return a.start < b.start;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<Movie> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].start >> movies[i].end;
        movies[i].index = i;
    }

    sort(movies.begin(), movies.end(), funCmp<Movie>);

    multiset<int> moviesPlan;
    int nMovies = 0;
    int clubMember = 0;

    for (int i = 0; i < k; i++) {
        moviesPlan.insert(-1);
    }

    for (int i = 0; i < n; i++) {
        auto it = moviesPlan.upper_bound(movies[i].start);

        if (it == moviesPlan.begin()) {
            continue;
        }

        moviesPlan.erase(--it);

        moviesPlan.insert(movies[i].end);
        nMovies++;
    }

    cout << nMovies;
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