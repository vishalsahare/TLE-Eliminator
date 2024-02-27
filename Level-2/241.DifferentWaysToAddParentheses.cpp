#include <bits/stdc++.h>
using namespace std;

//------------
#define endl "\n"
#define ll long long int

const int MOD = 1e9 + 7;
const int INF = LONG_MAX > 1;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//------------
vector<int> solve(int start, int end, string &expr) {

    int length = end-start+1;
    if (length <= 2) {
        return {stoi(expr.substr(start, length))};
    }

    vector<int>possibleValues;

    for(int i = start; i <= end; i++) {

        if (expr[i] == '+' or expr[i] == '-' or expr[i] == '*') {

            vector<int> left = solve(start, i-1, expr);
            vector<int> right = solve(i+1, end, expr);
            // debug(left);
            // debug(right);
            for (auto &x: left) {
                for (auto &y: right) {
                    if (expr[i] == '+') possibleValues.push_back(x + y);
                    if (expr[i] == '-') possibleValues.push_back(x - y);
                    if (expr[i] == '*') possibleValues.push_back(x * y);
                    
                }
            }
        }
    }
    // debug(possibleValues);
    return possibleValues;
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
        string s; cin >> s;

        // cout << s << endl;
        solve(0, s.size()-1, s);
        cout << endl;
    }

    return 0;
}