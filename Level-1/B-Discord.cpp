#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;


//------------
void solve() {

    int N, M; cin >> N >> M;
    int A[M][N];
    int V[N];
    memset(V, 0, sizeof(V);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i-1][j-1];
        }
    }

    for (int i = 0; i < N; i++) {
        V[i] = 1;

        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {

                if(A)
            }
        
        }
    }
    for (auto it = mapOfSet.begin(); it != mapOfSet.end(); it++) {

        int key = it->first;
        set<int> st = it->second;

        cout << key << " ===> ";
        for (auto it = st.begin(); it!= st.end(); it++) {
            cout << *it << " ";            
        }

        cout << endl;
    }

    int prev, curr;
    cin >> curr;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N-1; j++) {
            prev = curr;
            cin >> curr;

            mapOfSet[prev].erase(curr);
            mapOfSet[curr].erase(prev);
        }
    }

    for (auto it = mapOfSet.begin(); it != mapOfSet.end(); it++) {

        int key = it->first;
        set<int> st = it->second;

        cout << key << " ===> ";
        for (auto it = st.begin(); it!= st.end(); it++) {
            cout << *it << " ";            
        }

        cout << endl;
    }

    int ans = 0;
    for (auto it = mapOfSet.begin(); it != mapOfSet.end(); it++) {

        int key = it->first;
        set<int> st = it->second;

        for (auto it = st.begin(); it!= st.end(); it++) {
            
            mapOfSet[key].erase(*it);
            mapOfSet[*it].erase(key);
            ans++;
        }
    }

    cout << ans;
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

    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}