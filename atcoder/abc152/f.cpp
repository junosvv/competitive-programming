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
#define vpii vector<pii>
#define vt3i vector<t3i>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)
 
long long INF = 1LL<<60;
long long MOD = 1e9+7;

string to_string(char &c) {string x(1, c); return x;}
string to_string(const char s[]) {return (string)s;}
string to_string(string &s) {return s;}
string to_string(vb &v) {string res; for (const bool &x : v) res += to_string(x) + ' '; return res;}
template <class C> string to_string(C &v) {string res; for (auto &x : v) res += to_string(x) + ' '; return res;}
template <typename A, typename B> istream &operator>>(istream &is, pair<A, B> &pr) {is >> pr.first >> pr.second; return is;}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {for (auto &x : v) is >> x; return is;}
ostream &operator<<(ostream &os, char &c) {os << (char)c; return os;}
ostream &operator<<(ostream &os, const char s[]) {os << (string)s; return os;}
ostream &operator<<(ostream &os, string &s) {for (char &c : s) os << (char)c; return os;}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> pr) {os << '(' << pr.first << ", " << pr.second << ')'; return os;}
ostream &operator<<(ostream &os, vb &v) {
    bool first = true;
    os << '[';
    for (const bool &x : v) {
        if (!first) os << ", ";
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
        if (!first) os << ", ";
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

vvi nodes, par;
void precalc(int x, int u, int p=-1) {
    for (int v : nodes[u]) if (v != p) {
        par[v][x] = u;
        precalc(x, v, u);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    nodes.resize(n);
    par.assign(n, vi(n, -1));
    map<pii, int> edgeID;
    REP(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
        edgeID[{a, b}] = edgeID[{b, a}] = i;
    }

    vi tk(n+1, 1);
    REP(i, 1, n+1) tk[i] = 2*tk[i-1];

    REP(i, 0, n) precalc(i, i);

    int m;
    cin >> m;

    vpii paths(m);
    REP(i, 0, m) {
        cin >> paths[i];
        --paths[i].first; --paths[i].second;
    }

    int res = tk[n-1];
    vvb whites(1<<m, vb(n-1));
    REP(mask, 1, 1<<m) {
        int flip = __builtin_ctzll(mask);
        REP(i, 0, n-1) whites[mask][i] = whites[mask ^ 1<<flip][i];
        int u = paths[flip].first, v = paths[flip].second;
        while (u != v) {
            whites[mask][edgeID[{u, par[u][v]}]] = true;
            u = par[u][v];
        }
        int cur = 0;
        REP(i, 0, n-1) if (!whites[mask][i]) ++cur;
        if (__builtin_parityll(mask)) res -= tk[cur];
        else res += tk[cur];
    }
    print(res);
}