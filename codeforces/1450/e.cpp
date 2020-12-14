#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dub long double
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define CASET int _T; cin >> _T; FOR(caset, 1, _T+1)
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define mii map<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define vpii vector<pii>
#define vt3i vector<t3i>
#define vvpii vector<vpii>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SIZE(x) (int)(x).size()
#define SUM(x) accumulate(ALL(x), 0LL)

long long INF = 1LL<<60;
long long MOD = 1e9 + 7;

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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vvi dist(n, vi(n, INF));
    FOR(i, 0, m) {
        int x, y, t;
        cin >> x >> y >> t;
        --x; --y;
        if (t == 0) {
            dist[x][y] = 1;
            dist[y][x] = 1;
        } else {
            dist[x][y] = 1;
            dist[y][x] = -1;
        }
    }
    FOR(i, 0, n) dist[i][i] = 0;
    vi colour(n, -1);
    function<void(int)> dfs = [&](int u) {
        FOR(v, 0, n) {
            if (abs(dist[u][v]) == 1) {
                if (colour[v] == -1) {
                    colour[v] = !colour[u];
                    dfs(v);
                } else if (colour[v] == colour[u]) {
                    print("NO");
                    exit(0);
                }
            }
        }
    };
    colour[0] = 0;
    dfs(0);

    FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) {
        mini(dist[i][j], dist[i][k] + dist[k][j]);
    }
    FOR(i, 0, n) {
        if (dist[i][i] < 0) {
            print("NO");
            exit(0);
        }
    }
    print("YES");
    int x=0, y=0;
    FOR(i, 0, n) FOR(j, 0, n) {
        if (dist[i][j] > dist[x][y]) {
            x = i;
            y = j;
        }
    }
    print(dist[x][y]);
    FOR(i, 0, n) {
        cout << dist[x][i] << ' ';
    }
}

