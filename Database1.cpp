#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"

//------------
void solve(int t) {
    int n, r;
    cin >> n >> r;

    set<int> students[n + 1];
    int id, courseId;

    for (int i = 0; i < r; i++) {
        cin >> id >> courseId;

        if (!students[id].empty()) {
            if (students[id].count(courseId)) {
                cout << "Scenario #" << t << ": impossible";
                return;
            } else {
                students[id].insert(courseId);
            }
        } else {
            students[id].insert(courseId);
        }
    }

    cout << "Scenario #" << t << ": possible";
}

//------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;

    int i = 1;
    while (t--) {
        solve(i++);
        cout << endl;
    }

    return 0;
}