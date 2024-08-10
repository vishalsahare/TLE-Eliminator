#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll unsigned long long
// #define ll int64_t

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

//------------

bool possible(ll target, vector<ll> &A, ll k) {
    ll currentSubarraySum = 0;
    ll currentSubarray = 1;

    for (ll i = 0; i < A.size(); i++) {
        if (A[i] > target) {
            return false;
        } else {
            if (currentSubarraySum + A[i] <= target) {
                currentSubarraySum += A[i];
            } else {
                if (currentSubarray == k) {
                    return false;
                }
                currentSubarray++;
                currentSubarraySum = 0;
                currentSubarraySum += A[i];
            }
        }
    }

    return true;
}

// bool possible(ll target, vector<ll> &A, ll k) {
//     ll currentSubarraySum = 0;
//     ll currentSubarray = 1;

//     for (ll i = 0; i < A.size(); i++) {
//         if (currentSubarraySum + A[i] > target) {
//             currentSubarray++;
//             currentSubarraySum = 0;
//         }

//         currentSubarraySum += A[i];
//     }

//     return (currentSubarray <= k);
// }

void solve() {
    ll n, k;
    cin >> n >> k;

    ll left = 0;
    ll right = 1e18;
    // ll right = 0;

    vector<ll> A(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
        left = max(left, A[i]);
        // right += A[i];
    }

    // cout << left << " " << right << endl;

    ll res = 1e18;

    // int count = 1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        // cout << count++ << endl;
        if (possible(mid, A, k)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
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

    ll t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}