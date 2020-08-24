#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
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

vi par;
int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

vi state, numtaken, numavoid;
int contr(int u) {
    if (state[u] == -1) return min(numtaken[u], numavoid[u]);
    if (state[u]) return numtaken[u];
    return numavoid[u];
}

vector<vpii> nodes;
vb taken, seen;
void dfs(int u, int p=-1) {
    if (seen[u]) return;
    seen[u] = true;
    for (pii pr : nodes[u]) if (pr.first!=p) {
        taken[pr.first] = taken[u] ^ !pr.second;
        dfs(pr.first, u);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vb s(n);
    REP(i, 0, n) {
        char x;
        cin >> x;
        s[i] = x=='1';
    }
    vvi occ(n);
    REP(i, 0, k) {
        int sz;
        cin >> sz;
        REP(j, 0, sz) {
            int x;
            cin >> x;
            --x;
            occ[x].push_back(i);
        }
    }
    nodes.resize(k);
    int start = 0;
    bool sw = false;
    vi reqs;
    taken.resize(k);
    REP(i, 0, n) {
        if (occ[i].size() == 1) {
            taken[occ[i][0]] = !s[i];
            reqs.push_back(occ[i][0]);
        } else if (occ[i].size() == 2) {
            nodes[occ[i][0]].push_back({occ[i][1], s[i]});
            nodes[occ[i][1]].push_back({occ[i][0], s[i]});
        }
    }
    seen.resize(k);
    for (int i : reqs) dfs(i);
    REP(i, 0, k) dfs(i);

    par.resize(k);
    numtaken.resize(k);
    numavoid.resize(k);
    state.resize(k);
    REP(i, 0, k) {
        par[i] = i;
        numtaken[i] = taken[i];
        numavoid[i] = !taken[i];
        state[i] = -1;
    }

    int res = 0;
    REP(i, 0, n) {
        if (occ[i].size() == 1) {
            int x = find(occ[i][0]);
            res -= contr(x);
            state[x] = taken[occ[i][0]] == !s[i];
            res += contr(x);
        } else if (occ[i].size() == 2) {
            int x = find(occ[i][0]), y = find(occ[i][1]);
            if (x != y) {
                res -= contr(x);
                res -= contr(y);
                numtaken[y] += numtaken[x];
                numavoid[y] += numavoid[x];
                state[y] = max(state[y], state[x]);
                par[x] = y;
                res += contr(y);
            }
        }
        cout << res << '\n';
    }
}