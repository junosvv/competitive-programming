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
vi lev, backs, bigcomp;
void backdfs(int big, int u) {
    bigcomp[u] = big;
    for (int v : nodes[u]) {
        if (lev[v] == 0) {
            lev[v] = 1 + lev[u];
            backdfs(big, v);
            backs[u] += backs[v];
        } else if (lev[v] < lev[u] - 1) {
            ++backs[u];
        } else if (lev[v] > lev[u] + 1) {
            --backs[u];
        }
    }
}

int t;
vi comp, tin, tout, par;
const int K = 25;
vvi up, newnodes;
void compdfs(int u) {
    tin[u] = t++;
    for (int v : nodes[u]) {
        if (lev[v] == 0) {
            lev[v] = 1 + lev[u];
            if (backs[v]) {
                comp[v] = comp[u];
            } else {
                comp[v] = v;
                par[comp[v]] = comp[u];
                newnodes[comp[u]].push_back(comp[v]);
                newnodes[comp[v]].push_back(comp[u]);
                up[comp[v]][0] = comp[u];
                FOR(k, 1, K) up[comp[v]][k] = up[up[comp[v]][k-1]][k-1];
            }
            compdfs(v);
        }
    }
    tout[u] = t++;
}

bool isanc(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
    if (isanc(u, v)) return u;
    if (isanc(v, u)) return v;
    ROF(k, K-1, -1) if (!isanc(up[u][k], v)) u = up[u][k];
    return up[u][0];
}

vi reds, blus, redcnt, blucnt;
void coldfs(int u) {
    for (int v : newnodes[u]) if (lev[v] == 0) {
        lev[v] = 1 + lev[u];
        coldfs(v);
        redcnt[u] += redcnt[v];
        blucnt[u] += blucnt[v];
    }
    redcnt[u] += reds[u];
    blucnt[u] += blus[u];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    nodes.resize(n);
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }

    lev.resize(n);
    backs.resize(n);
    bigcomp.resize(n);
    FOR(i, 0, n) if (lev[i] == 0) {
        lev[i] = 1;
        backdfs(i, i);
    }
    
    lev.assign(n, 0);
    comp.resize(n);
    up.assign(n, vi(25));
    tin.resize(n);
    tout.resize(n);
    par.resize(n);
    newnodes.resize(n);
    FOR(i, 0, n) if (lev[i] == 0) {
        lev[i] = 1;
        comp[i] = i;
        FOR(k, 0, K) up[i][k] = i;
        par[i] = i;
        compdfs(i);
    }

    reds.resize(n);
    blus.resize(n);
    redcnt.resize(n);
    blucnt.resize(n);

    FOR(_, 0, q) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        x = comp[x];
        y = comp[y];
        if (bigcomp[x] != bigcomp[y]) {
            print("No");
            exit(0);
        }
        int z = lca(x, y);

        ++reds[x];
        --reds[z];
        ++blus[y];
        --blus[z];
    }

    lev.assign(n, 0);
    FOR(i, 0, n) if (lev[comp[i]] == 0) {
        lev[comp[i]] = 1;
        coldfs(comp[i]);
    }
    FOR(i, 0, n) if (redcnt[comp[i]] > 0 && blucnt[comp[i]] > 0) {
        int cnt = 0;
        for (int v : nodes[comp[i]]) if (v == par[comp[i]]) ++cnt;
        if (cnt == 1) {
            print("No");
            exit(0);
        }
    }
    print("Yes");
}