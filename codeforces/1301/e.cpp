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
 
main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int R, C, Q;
    cin >> R >> C >> Q;

    vi lg(505);
    FOR(i, 2, lg.size()) lg[i] = 1 + lg[i/2];
 
    vvi grid(R+1, vi(C+1));
    vector<vvi> grids(4, vvi(R+1, vi(C+1)));
    FOR(r, 1, R+1) FOR(c, 1, C+1) {
        char x;
        cin >> x;
        FOR(i, 0, 4) if ("RGYB"[i] == x) grid[r][c] = i;
        grids[grid[r][c]][r][c] = 1;
    }
    FOR(g, 0, 4) FOR(r, 1, R+1) FOR(c, 1, C+1) grids[g][r][c] += grids[g][r-1][c] + grids[g][r][c-1] - grids[g][r-1][c-1];

    vvi red(R+1, vi(C+1));
    FOR(r, 1, R+1) FOR(c, 1, C+1) if (grid[r][c] == 0) red[r][c] = 1 + min(red[r-1][c], min(red[r][c-1], red[r-1][c-1]));

    auto gquery = [&](vvi &grid, int r1, int c1, int sz) {
        return grid[r1][c1] - grid[r1-sz][c1] - grid[r1][c1-sz] + grid[r1-sz][c1-sz];
    };

    const int K = 10;
    vector<vector<vvi>> sparse(K, vector<vvi>(K, vvi(R+1, vi(C+1))));
    FOR(r, 1, R+1) FOR(c, 1, C+1) if (red[r][c]) {
        int sz = red[r][c];
        if (r+sz <= R && c+sz <= C && sz*sz == gquery(grids[1], r, c+sz, sz) && sz*sz == gquery(grids[2], r+sz, c, sz) && sz*sz == gquery(grids[3], r+sz, c+sz, sz)) {
            sparse[0][0][r][c] = sz;
        }
    }

    FOR(y, 1, K) FOR(r, 1, R+1) {
        FOR(c, 1, C+1) {
            if (c + (1<<y-1) > C) break;
            sparse[0][y][r][c] = max(sparse[0][y-1][r][c], sparse[0][y-1][r][c + (1<<y-1)]);
        }
    }

    FOR(x, 1, K) FOR(y, 0, K) FOR(r, 1, R+1) {
        if (r + (1<<x-1) > R) break;
        FOR(c, 1, C+1) {
            if (c + (1<<y-1) > C) break;
            sparse[x][y][r][c] = max(sparse[x-1][y][r][c], sparse[x-1][y][r + (1<<x-1)][c]);
        }
    }

    auto squery = [&](int r1, int c1, int r2, int c2) {
        int kr = lg[r2-r1+1];
        int kc = lg[c2-c1+1];
        int m1 = max(sparse[kr][kc][r1][c1], sparse[kr][kc][r2-(1<<kr)+1][c1]);
        int m2 = max(sparse[kr][kc][r1][c2-(1<<kc)+1], sparse[kr][kc][r2-(1<<kr)+1][c2-(1<<kc)+1]);
        return max(m1, m2);
    };

    FOR(q, 0, Q) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int k = 0;
        int upp = 255;
        for (int b=upp; b>=1; b/=2) {
            while (k+b < upp) {
                int check = k+b;
                int sr = r1 + check - 1;
                int sc = c1 + check - 1;
                int er = r2 - check;
                int ec = c2 - check;
                if (sr > er || sc > ec) break;
                if (squery(sr, sc, er, ec) < check) break;
                k += b;
            }
        }
        cout << 4*k*k << '\n';
    }
}