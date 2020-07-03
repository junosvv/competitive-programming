#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define dub long double
#define FOR(i, a, b) for (int (i)=(a); (i)<(b); ++(i))
#define ROF(i, a, b) for (int (i)=(a); (i)>(b); --(i))
#define CASET int _T; cin >> _T; FOR(caset, 1, _T+1)
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define mii map<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvvi vector<vvi>
#define vvvb vector<vvb>
#define vpii vector<pii>
#define vt3i vector<t3i>
#define vvpii vector<vpii>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SIZE(x) (signed)(x).size()
#define SUM(x) accumulate(ALL(x), 0LL)
 
long long INF = 1LL<<60;
long long MOD = 1e9+7;
 
namespace output {
    void pr(short x) { cout << x; }
    void pr(signed x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(long long x) { cout << x; }
    void pr(unsigned short x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(long double x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { cout << x; }
    template<size_t sz> void pr(const bitset<sz>& x) { cout << x; }
    template<class T> void pr(const complex<T>& x) { cout << x; }
    
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T1, class T2, class T3> void pr(const tuple<T1,T2,T3>& x);
    template<class T> void pr(const T& x);
    
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { pr("(",x.first,", ",x.second,")"); }
    template<class T1, class T2, class T3> void pr(const tuple<T1,T2,T3>& x) { pr("(",get<0>(x),", ",get<1>(x),", ",get<2>(x),")"); }
    template<class T> void pr(const T& x) { 
        pr("["); // const iterator needed for vector<bool>
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
        pr("]");
    }
    
    void print() { pr("\n"); } // print w/ spaces
    template<class T, class... Ts> void print(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); print(ts...); }
}
using namespace output;
 
template <class T1, class T2> istream &operator>>(istream &is, pair<T1,T2> &x) { is >> x.first >> x.second; return is; }
template <class T1, class T2, class T3> istream &operator>>(istream &is, tuple<T1,T2,T3> &x) { is >> get<0>(x) >> get<1>(x) >> get<2>(x); return is; }
template <class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}
bool mini(int &a, int b) { return b < a ? a = b, 1 : 0; }
bool maxi(int &a, int b) { return b > a ? a = b, 1 : 0; }

// int rook(vvi &grid) {
//     int pr, pc;
//     FOR(r, 0, 3) FOR(c, 0, 3) if (grid[r][c] == 1) pr = r, pc = c;
//     int res = 0;
//     vvb seen(3, vb(3));
//     while (true) {
//         seen[pr][pc] = true;
//         int nr, nc=-1;
//         FOR(r, 0, 3) if (!seen[r][pc] && (nc == -1 || grid[r][pc] < grid[nr][nc])) nr = r, nc = pc;
//         FOR(c, 0, 3) if (!seen[pr][c] && (nc == -1 || grid[pr][c] < grid[nr][nc])) nr = pr, nc = c;
//         if (nc == -1) {
//             FOR(r, 0, 3) FOR(c, 0, 3) if (!seen[r][c] && (nc == -1 || grid[r][c] < grid[nr][nc])) nr = r, nc = c;
//             if (nc == -1) break;
//             ++res;
//         }
//         pr = nr;
//         pc = nc;
//     }
//     return res;
// }

// int queen(vvi &grid) {
//     int pr, pc;
//     FOR(r, 0, 3) FOR(c, 0, 3) if (grid[r][c] == 1) pr = r, pc = c;
//     int res = 0;
//     vvb seen(3, vb(3));
//     while (true) {
//         seen[pr][pc] = true;
//         int nr, nc=-1;
//         FOR(r, 0, 3) if (!seen[r][pc] && (nc == -1 || grid[r][pc] < grid[nr][nc])) nr = r, nc = pc;
//         FOR(c, 0, 3) if (!seen[pr][c] && (nc == -1 || grid[pr][c] < grid[nr][nc])) nr = pr, nc = c;
//         FOR(d, -3, 4) if (d != 0) {
//             int rr = pr + d;
//             int cc = pc + d;
//             if (rr < 0 || rr > 2 || cc < 0 || cc > 2) continue;
//             if (!seen[rr][cc] && (nc == -1 || grid[rr][cc] < grid[nr][nc])) nr = rr, nc = cc;
//         }
//         FOR(d, -3, 4) if (d != 0) {
//             int rr = pr - d;
//             int cc = pc + d;
//             if (rr < 0 || rr > 2 || cc < 0 || cc > 2) continue;
//             if (!seen[rr][cc] && (nc == -1 || grid[rr][cc] < grid[nr][nc])) nr = rr, nc = cc;
//         }
//         if (nc == -1) {
//             FOR(r, 0, 3) FOR(c, 0, 3) if (!seen[r][c] && (nc == -1 || grid[r][c] < grid[nr][nc])) nr = r, nc = c;
//             if (nc == -1) break;
//             ++res;
//         }
//         pr = nr;
//         pc = nc;
//     }
//     return res;
// }

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    vvi silly = {
        {1, 2, 4},
        {5, 3, 8},
        {9, 6, 7}
    };

    int n;
    cin >> n;
    if (n <= 2) print(-1);
    else {
        vvi grid(n, vi(n));
        int cnt = 1;
        bool vert = false;
        ROF(i, n-1, 2) {
            if (!vert) {
                FOR(j, 0, i+1) grid[i][j] = cnt++;
                ROF(j, i-1, -1) grid[j][i] = cnt++;
            } else {
                FOR(j, 0, i+1) grid[j][i] = cnt++;
                ROF(j, i-1, -1) grid[i][j] = cnt++;
            }
            vert = !vert;
        }
        FOR(i, 0, 3) FOR(j, 0, 3) grid[i][j] = silly[i][j] + cnt - 1;
        FOR(i, 0, n) {
            FOR(j, 0, n) cout << grid[i][j] << ' ';
            cout << '\n';
        }
    }
}