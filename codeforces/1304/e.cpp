#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, b, a) for (int i=(b); i>(a); --i)
#define CASET int _T; cin >> _T; FOR(caset, 0, _T)
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
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> &pr) {os << '(' << pr.first << ", " << pr.second << ')'; return os;}
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
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}

vector<vi> nodes;
vb parity;
vi toroot;
void mydfs(int u, int p=-1) {
    for (int v : nodes[u]) if (v != p) {
        parity[v] = !parity[u];
        toroot[v] = toroot[u]+1;
        mydfs(v, u);
    }
}

// cp.algorithms
int n, l;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : nodes[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n)) + 2;
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int distf(int a, int b) {
    return toroot[a] + toroot[b] - 2*toroot[lca(a, b)];
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    nodes.resize(n);
    FOR(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    parity.resize(n);
    toroot.resize(n);
    mydfs(0);

    preprocess(0);

    int q;
    cin >> q;
    FOR(_, 0, q) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        --x; --y; --a; --b;
        if (parity[x] != parity[y]) {
            // edge does nothing
            if ((parity[a] != parity[b]) != (k&1)) cout << "NO\n";
            else {
                int d = min(distf(a, b), min(distf(a, x)+1+distf(y, b), distf(a, y)+1+distf(x, b)));
                if (d <= k) cout << "YES\n";
                else cout << "NO\n";
            }
        } else {
            // edge is weird
            if ((parity[a] != parity[b]) != (k&1)) {
                // use weird edge
                int d = min(distf(a, x)+1+distf(y, b), distf(a, y)+1+distf(x, b));
                if (d <= k) cout << "YES\n";
                else cout << "NO\n";
            } else {
                // dont
                int d = distf(a, b);
                if (d <= k) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}

/*
7
1 2
2 4
2 5
1 3
3 6
3 7
1
*/