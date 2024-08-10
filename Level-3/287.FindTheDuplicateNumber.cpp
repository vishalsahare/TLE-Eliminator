#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------

// bool predicateFunc(int mid, vector<int> &nums, int n) {
//     int slow = -1;
//     int fast = nums[0];

//     while (slow != fast and slow < n and fast < n) {
//         slow = nums[slow];
//         fast = nums[nums[fast]];
//     }
// }

void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int L = 1;
    int R = n;

    int res = 0;
    while (L <= R) {
        int mid = (L + R) / 2;

        cout << L << " " << R << " " << mid << endl;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid)
                cnt++;
        }
        cout << cnt << endl;
        if (cnt <= mid) {
            L = mid + 1;
        } else {
            res = mid;
            R = mid - 1;
        }
    }

    cout << res;
}

//------------
int main() {
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