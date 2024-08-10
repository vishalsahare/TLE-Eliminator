#include <bits/stdc++.h>
using namespace std;

#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)

string lstrip(string s) {
    int i;
    for (i = 0; i < (int)s.size() && s[i] == ' '; i++);
    return s.substr(i);
}

// Function prototypes

string to_string(string s);
string to_string(const char* s);
string to_string(bool b);
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A>
string to_string(A v);
template <typename A>
string to_string(A v[], int n);
template <typename A>
string to_string(A v[], int n);
string to_string(stack<int> stk);
string to_string(queue<int> que);

template <typename Head, typename Size, typename... Tail>
void debug_out(string V, Head H[], Size N, Tail... T);

template <typename Head, typename... Tail>
void debug_out(string V, Head H, Tail... T);

void debug_out(string V);

// Actual functions

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "[";
    for (const auto& x : v) {
        if (!first)
            res += ", ";

        first = false;
        res += to_string(x);
    }

    return res + "]";
}

template <typename A>
string to_string(A v[], int n) {
    string res = "[";

    for (int i = 0; i < n; i++) {
        A x = v[i];
        if (i)
            res += ", ";

        res += to_string(x);
    }

    return res + "]";
}

string to_string(stack<int> stk) {
    vector<int> v;
    while (!stk.empty())
        v.push_back(stk.top()), stk.pop();

    reverse(v.begin(), v.end());
    return to_string(v);
}

string to_string(queue<int> que) {
    vector<int> v;
    while (!que.empty())
        v.push_back(que.front()), que.pop();

    return to_string(v);
}

template <typename Head, typename Size, typename... Tail>
void debug_out(string V, Head H[], Size N, Tail... T) {
    int idx = V.find(',');

    cerr << V.substr(0, idx) << ": " << to_string(H, N);
    if (sizeof...(T)) cerr << ", ";

    V = V.substr(idx + 1);
    idx = V.find(',');
    debug_out(lstrip(V.substr(idx + 1)), T...);
}

template <typename Head, typename... Tail>
void debug_out(string V, Head H, Tail... T) {
    int idx = V.find(',');

    cerr << V.substr(0, idx) << ": " << to_string(H);
    if (sizeof...(T)) cerr << ", ";

    debug_out(lstrip(V.substr(idx + 1)), T...);
}

void debug_out(string V) { cerr << endl; }