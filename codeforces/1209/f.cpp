#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define print(x) cout << to_string(x) << '\n'
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define mii map<int,int>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)
 
long long INF = 1LL<<60;
int MOD = 1e9+7;

string to_string(char &c) {string x(1, c); return x;}
string to_string(string &s) {return s;}
string to_string(const char s[]) {return (string)s;}
string to_string(vb &v) {
    string res;
    for (const bool &x : v) res += to_string(x) + ' ';
    return res;
}
template <class C> string to_string(C &v) {
    string res;
    for (auto &x : v) res += to_string(x) + ' ';
    return res;
}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {
    for (auto &x : v) is >> x;
    return is;
}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> pr) {
    os << '(' << pr.first << ", " << pr.second << ')';
    return os;
}
ostream &operator<<(ostream &os, char &c) {os << (char)c; return os;}
ostream &operator<<(ostream &os, string &s) {for (char &c : s) os << (char)c; return os;}
ostream &operator<<(ostream &os, const char s[]) {os << (string)s; return os;}
ostream &operator<<(ostream &os, vb &v) {
    bool first = true;
    os << '[';
    for (const bool &x : v) {
        if (!first) os << ',' << ' ';
        first = false;
        os << x;
    }
    os << ']';
    return os;
}
template <class C> ostream &operator<<(ostream &os, C &v) {
    bool first = true;
    os << '[';
    for (auto &x : v) {
        if (!first) os << ',' << ' ';
        first = false;
        os << x;
    }
    os << ']';
    return os;
}
string bin_string(int x) {
    const int d = 32;
    string res(d, ' ');
    REP(i, 0, d) res[d-1-i] = '0'+(x>>i & 1LL);
    return res;
}
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n,m;
    cin >> n >> m;
    vector<vvi> edges(n+1, vvi(10));
    REP(i, 1, m+1) {
        int x, y;
        cin >> x >> y;
        int prev = x;
        vi digits;
        for (char c : to_string(i)) digits.push_back(c-'0');
        REP(j, 0, digits.size()-1) {
            edges[prev][digits[j]].push_back(edges.size());
            vvi temp(10);
            edges.push_back(temp);
            edges.back()[digits[digits.size()-1-j]].push_back(prev);
            prev = edges.size()-1;
        }
        edges[prev][digits.back()].push_back(y);
        edges[y][digits[0]].push_back(prev);
    }
    int n0 = n; n = edges.size()-1;
    vi res(n+1, -1);
    queue<vi> q;
    q.push({1});
    res[1] = 0;
    while (!q.empty()) {
        vi verts = q.front();
        q.pop();
        vi nxt;
        REP(w, 0, 10) {
            for (int u : verts) {
                for (int v : edges[u][w]) {
                    if (res[v] == -1) {
                        res[v] = (res[u] * 10LL % MOD + w) % MOD;
                        nxt.push_back(v);
                    }
                }
            }
            if (nxt.size()) q.push(nxt);
        }
    }
    REP(i, 2, n0+1) cout << res[i] << '\n';
}