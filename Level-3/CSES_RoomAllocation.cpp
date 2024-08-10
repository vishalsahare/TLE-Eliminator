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
struct Person {
    int arr;
    int dep;
    int index;
};

template <class T>
bool funcCmp(T a, T b) {
    return a.arr < b.arr;
}

void solve() {
    int n;
    cin >> n;

    vector<Person> cust(n);
    vector<int> res(n);
    set<pair<int, int> > rooms;  // { dep + 1, roomNo}

    for (int i = 0; i < n; i++) {
        cin >> cust[i].arr >> cust[i].dep;
        cust[i].index = i;
    }

    sort(cust.begin(), cust.end(), funcCmp<Person>);
    // debug(cust.size());
    int roomCount = 0;
    for (auto per : cust) {
        int rNo = 0;
        // Check if empty room exists
        // debug(per.arr, per.dep, per.index);
        if (rooms.empty() or per.arr < rooms.begin()->first) {
            rNo = ++roomCount;
        } else {
            rNo = rooms.begin()->second;
            rooms.erase(rooms.begin());
        }

        res[per.index] = rNo;
        pair<int, int> x = make_pair(per.dep + 1, rNo);
        rooms.insert(x);
        // debug(rooms);
    }

    cout << roomCount << endl;
    for (auto rCount : res) {
        cout << rCount << " ";
    }
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