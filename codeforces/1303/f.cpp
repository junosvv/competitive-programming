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

vector<vpii> par;
pii find(pii x) {
    pii &px = par[x.first][x.second];
    if (x == px) return x;
    return px = find(px);
}

int R, C, Q;
vvi grid;
void dfs(pii s, int r, int c) {
    if (par[r][c] != pii{-1, -1}) return;
    par[r][c] = s;
    for (pii delta : vpii{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}) {
        int rr = r+delta.first;
        int cc = c+delta.second;
        if (rr < 0 || rr >= R || cc < 0 || cc >= C || grid[r][c] != grid[rr][cc]) continue;
        dfs(s, rr, cc);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> R >> C >> Q;

    grid.assign(R, vi(C));
    vector<vt3i> addqueries, rmvqueries;
    FOR(q, 0, Q) {
        int r, c, v;
        cin >> r >> c >> v;
        --r; --c;
        while (addqueries.size() <= v) {
            addqueries.push_back({});
            rmvqueries.push_back({});
        }
        if (grid[r][c] == v) continue;
        addqueries[v].push_back({q, r, c});
        rmvqueries[grid[r][c]].push_back({q, r, c});
        grid[r][c] = v;
    }

    vi res(Q);
    par.assign(R, vpii(C));

    FOR(v, 0, addqueries.size()) {
        FOR(r, 0, R) FOR(c, 0, C) par[r][c] = {r, c};
        vvb coloured(R, vb(C));
        for (auto tup : addqueries[v]) {
            int q, r, c;
            tie(q, r, c) = tup;
            ++res[q];
            coloured[r][c] = true;
            for (pii delta : vpii{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}) {
                int rr = r+delta.first;
                int cc = c+delta.second;
                if (rr < 0 || rr >= R || cc < 0 || cc >= C || !coloured[rr][cc]) continue;
                tie(rr, cc) = find({rr, cc});
                int fr, fc;
                tie(fr, fc) = find({r, c});
                if (pii{fr, fc} == pii{rr, cc}) continue;
                par[fr][fc] = {rr, cc};
                --res[q];
            }
        }

        FOR(r, 0, R) FOR(c, 0, C) par[r][c] = {-1, -1};
        FOR(r, 0, R) FOR(c, 0, C) {
            coloured[r][c] = grid[r][c] == v;
            if (grid[r][c] == v) dfs({r, c}, r, c);
        }
        FOR(r, 0, R) FOR(c, 0, C) if (par[r][c] == pii{-1, -1}) par[r][c] = {r, c};

        reverse(rmvqueries[v].begin(), rmvqueries[v].end());
        for (auto tup : rmvqueries[v]) {
            int q, r, c;
            tie(q, r, c) = tup;
            --res[q];
            coloured[r][c] = true;
            for (pii delta : vpii{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}) {
                int rr = r+delta.first;
                int cc = c+delta.second;
                if (rr < 0 || rr >= R || cc < 0 || cc >= C || !coloured[rr][cc]) continue;
                tie(rr, cc) = find({rr, cc});
                int fr, fc;
                tie(fr, fc) = find({r, c});
                if (pii{fr, fc} == pii{rr, cc}) continue;
                par[fr][fc] = {rr, cc};
                ++res[q];
            }
        }
    }
    ++res[0];
    FOR(i, 1, Q) res[i] += res[i-1];
    FOR(i, 0, Q) cout << res[i] << '\n';
}