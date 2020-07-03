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
#define vpii vector<pii>
#define vt3i vector<t3i>
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
 
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }

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

vvi nodes;
vi lev, badbacks, anybacks;
bool isbip;
int totbadbacks;
int badback;
map<pii, int> id;
void dfs(int u) {
    for (int v : nodes[u]) {
        if (lev[v] == 0) {
            lev[v] = 1 + lev[u];
            dfs(v);
            badbacks[u] += badbacks[v];
            anybacks[u] += anybacks[v];
        } else if (lev[v] < lev[u] - 1) {
            if (!(lev[u]-lev[v]&1)) {
                isbip = false;
                ++badbacks[u];
                ++totbadbacks;
                badback = id[{u, v}];
            }
            ++anybacks[u];
        } else if (lev[v] > lev[u]) {
            if (!(lev[v]-lev[u]&1)) --badbacks[u];
            --anybacks[u];
        }
    }
}

vb seen;
vi edges;
void dfs2(int u, int p=-1) {
    if (seen[u]) return;
    seen[u] = true;
    if (p != -1 && badbacks[u] == totbadbacks && badbacks[u] == anybacks[u]) edges.push_back(id[{u, p}]);
    for (int v : nodes[u]) {
        dfs2(v, u);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    nodes.resize(n);
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
        id[{x, y}] = id[{y, x}] = i;
    }
    
    lev.resize(n);
    badbacks.resize(n);
    anybacks.resize(n);
    seen.resize(n);
    bool badcomp = false;
    FOR(i, 0, n) {
        if (lev[i] == 0) {
            lev[i] = 1;
            isbip = true;
            totbadbacks = 0;
            dfs(i);
            if (!isbip) {
                if (badcomp) {
                    print(0);
                    exit(0);
                }
                badcomp = true;
                dfs2(i);
                if (totbadbacks == 1) edges.push_back(badback);
            }
        }
    }
    if (badcomp) {
        print(SIZE(edges));
        sort(ALL(edges));
        for (int i : edges) cout << i+1 << ' ';
    } else {
        print(m);
        FOR(i, 0, m) cout << i+1 << ' ';
    }
}