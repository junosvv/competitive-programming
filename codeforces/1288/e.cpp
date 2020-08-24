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
 
int INF = 1LL<<60;
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
    const int d = 6;
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

int n, m;
vi tree;
void upd(int l, int r, int delta) {
    l += n+m;
    r += n+m;
    while (l <= r) {
        if (l&1) tree[l++] += delta;
        if (!(r&1)) tree[r--] += delta;
        l /= 2;
        r /= 2;
    }
}

int get(int x) {
    x += n+m;
    int res = 0;
    while (x) {
        res += tree[x];
        x /= 2;
    }
    return res;
}
 
main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    vi msgs(m);
    cin >> msgs;
    REP(i, 0, m) --msgs[i];

    vi locs(n), mins(n), maxs(n);
    REP(i, 0, n) {
        mins[i] = maxs[i] = i;
        locs[i] = m+i;
    }

    tree.resize(2*(n+m));
    REP(i, 0, n) tree[n+m+m+i] = i;
    
    REP(i, 0, m) {
        maxs[msgs[i]] = max(maxs[msgs[i]], get(locs[msgs[i]]));
        upd(m-1-i, m-1-i, -1-get(m-1-i));
        upd(0, locs[msgs[i]], 1);
        locs[msgs[i]] = m-1-i;
        mins[msgs[i]] = min(mins[msgs[i]], get(locs[msgs[i]]));
    }
    REP(i, 0, n) {
        mins[i] = min(mins[i], get(locs[i]));
        maxs[i] = max(maxs[i], get(locs[i]));
    }

    REP(i, 0, n) cout << mins[i]+1 << ' ' << maxs[i]+1 << '\n';
}