#include <bits/stdc++.h>
using namespace std;
 
#define lglg long long
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

const int NAX = 4*4e5+5;
vvi nodes(NAX), invnodes(NAX);
vb koseen(NAX);
vi tour, comp(NAX);
int curcomp = 1;
void invkos(int u) {
    if (comp[u]) return;
    comp[u] = curcomp;
    for (int v : invnodes[u]) {
        invkos(v);
    }
}

void kos(int u) {
    if (koseen[u]) return;
    koseen[u] = true;
    for (int v : nodes[u]) {
        kos(v);
    }
    tour.push_back(u);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int orN, n, m, andN;
    cin >> orN >> n >> m >> andN;
    int p = n+m;
    int q = p+p;

    REP(i, 0, m-1) {
        nodes[n+i].push_back(n+i+1);
        nodes[p+n+i+1].push_back(p+n+i);
    }

    REP(i, 0, orN) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        nodes[p+a].push_back(b);
        nodes[p+b].push_back(a);
    }

    REP(i, 0, n) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (a != 0) {
            nodes[n+a-1].push_back(p+i);
            nodes[i].push_back(p+n+a-1);
        }
        nodes[p+n+b].push_back(p+i);
        nodes[i].push_back(n+b);
    }

    REP(i, 0, andN) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        nodes[a].push_back(p+b);
        nodes[b].push_back(p+a);
    }

    REP(u, 0, q) {
        for (int v : nodes[u]) invnodes[v].push_back(u);
    }

    REP(i, 0, q) kos(i);
    reverse(tour.begin(), tour.end());
    for (int u : tour) if (!comp[u]) {
        invkos(u);
        ++curcomp;
    }

    vb active(p);
    REP(u, 0, p) {
        if (comp[u] == comp[p+u]) {
            print(-1);
            return 0;
        }
        if (comp[p+u] < comp[u]) active[u] = true;
    }
    
    int k=0, f=1;
    REP(i, 0, n) if (active[i]) ++k;
    REP(i, n, n+m) if (!active[i]) ++f;
    cout << k << ' ' << f << '\n';
    REP(i, 0, n) if (active[i]) cout << i+1 << ' ';
}