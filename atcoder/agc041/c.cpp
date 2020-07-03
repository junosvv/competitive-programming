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

vvi grid(25, vi(25));
int n;
void rec(int r, int c, int cnt=1) {
    if (r == n) {
        FOR(j, 0, n) {
            set<int> seen;
            FOR(i, 0, n) if (grid[i][j]) seen.insert(grid[i][j]);
            if (seen.size() != 3) return;
        }
        FOR(i, 0, n) {
            FOR(j, 0, n) cout << (grid[i][j] ? (char)('a'+grid[i][j]-1) : '.');
            cout << '\n';
        }
        cout << '\n';
        exit(0);
    } else if (c == n) {
        set<int> seen;
        FOR(j, 0, n) if (grid[r][j]) seen.insert(grid[r][j]);
        if (seen.size() == 3) rec(r+1, 0, cnt);
    } else {
        rec(r, c+1, cnt);
        for (pii delta : vpii{{0, 1}, {1, 0}}) {
            int rr = r+delta.first;
            int cc = c+delta.second;
            if (rr < 0 || rr >= n || cc < 0 || cc >= n || grid[r][c] || grid[rr][cc]) continue;
            grid[r][c] = grid[rr][cc] = cnt;
            rec(r, c+1, cnt+1);
            grid[r][c] = grid[rr][cc] = 0;
        }
    }
}

vs results = {"", "", "", "aa...b..b",
    "aabcddbcefggefhh", // 4
    "..abc..abcddeefggh.fiihjj",
    "...abc...abcddee.f..gghfiij.h.kkj.ll",
    "....abc....abc....def....defgghh..ijjkk..illmmnn."
}; // size 8

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1;
        return 0;
    }
    vector<string> grid(n, string(n, '.'));
    int r = 0, c = 0;
    while (n >= 8) {
        FOR(i, 0, 4) FOR(j, 0, 4) grid[r+i][c+j] = results[4][i*4+j];
        n -= 4;
        r += 4;
        c += 4;
    }
    FOR(i, 0, n) FOR(j, 0, n) grid[r+i][c+j] = results[n][i*n+j];
    FOR(i, 0, grid.size()) {
        FOR(j, 0, grid[0].size()) cout << grid[i][j];
        cout << '\n';
    }
}