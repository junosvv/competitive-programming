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

vi tree, lazy;
int slots;
void inc(int x, int delta) {
    tree[x] += delta;
    if (x < slots) lazy[x] += delta;
}

void merge(int x) {
    tree[x] = lazy[x] + max(tree[2*x], tree[2*x+1]);
}

void fix(int x) {
    x /= 2;
    while (x) {
        merge(x);
        x /= 2;
    }
}

void upd(int l, int r, int delta) {
    l += slots;
    r += slots;
    int l0 = l;
    int r0 = r;
    while (l <= r) {
        if (l&1) inc(l++, delta);
        if (!(r&1)) inc(r--, delta);
        l /= 2;
        r /= 2;
    }
    fix(l0);
    fix(r0);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    slots = m-k+1;

    vvi grid(n, vi(m));
    cin >> grid;
    grid.push_back({});
    grid.back().resize(m);

    vvi dp(n+1, vi(slots));
    ROF(r, n-1, 0) {
        tree.assign(2*slots, 0);
        lazy.assign(slots, 0);
        int sm = 0;
        FOR(i, 0, k) sm += grid[r+1][i];
        tree[slots] = sm + dp[r+1][0];
        FOR(i, 1, slots) {
            sm += grid[r][k+i-1] + grid[r+1][k+i-1] - (i-1<=k-1 ? 0 : grid[r][i-1]) - grid[r+1][i-1];
            tree[slots+i] = sm + dp[r+1][i];
        }
        ROF(i, slots-1, 0) merge(i);
        dp[r][0] = tree[1];
        FOR(i, 1, slots) {
            upd(max(0LL, i-k), i-1, grid[r][i-1]);
            upd(i, min(slots-1, k+i-1), -grid[r][k+i-1]);
            dp[r][i] = tree[1];
        }
    }

    tree.assign(2*slots, 0);
    lazy.assign(slots, 0);
    int sm = 0;
    FOR(i, 0, k) sm += grid[0][i] + grid[1][i];
    tree[slots] = sm + dp[1][0];
    FOR(i, 1, slots) {
        sm += grid[0][k+i-1] + grid[1][k+i-1] - grid[0][i-1] - grid[1][i-1];
        tree[slots+i] = sm + dp[1][i];
    }
    ROF(i, slots-1, 0) merge(i);
    cout << tree[1];
}