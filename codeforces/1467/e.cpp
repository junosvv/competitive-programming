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
    
    int n;
    cin >> n;
    vi a(n);
    cin >> a;

    vvi nodes(n);
    FOR(i, 0, n-1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    
    vi tin(n), tout(n);
    int cnt = 0;
    map<int, vi> occ;
    vpii ranges;
    function<void(int,int)> tourdfs = [&](int u, int p) {
        occ[a[u]].push_back(cnt);
        tin[u] = cnt++;
        for (int v : nodes[u]) if (v != p) {
            tourdfs(v, u);
        }
        ranges.emplace_back(cnt, cnt);
        tout[u] = cnt++;
    };
    tourdfs(0, 0);

    auto f = [&](int x, int l, int r) {
        return lower_bound(ALL(occ[x]), r) - lower_bound(ALL(occ[x]), l);
    };
    
    function<void(int,int)> dfs = [&](int u, int p) {
        if (f(a[u], tin[u], tout[u]) < SIZE(occ[a[u]])) {
            ranges.emplace_back(tin[u], tout[u]);
        }
        int safe = -1;
        for (int v : nodes[u]) if (v != p) {
            if (f(a[u], tin[v], tout[v]) >= 1) {
                if (safe == -1) {
                    ranges.emplace_back(0, tin[u]);
                    ranges.emplace_back(tout[u], cnt-1);
                    for (int q : nodes[u]) if (q != p && q != v) {
                        ranges.emplace_back(tin[q], tout[q]);
                    }
                    safe = v;
                } else if (safe != -2) {
                    ranges.emplace_back(tin[safe], tout[safe]);
                    safe = -2;
                }
            }
            dfs(v, u);
        }
    };
    dfs(0, 0);

    sort(ALL(ranges));
    int res = 0;
    int prev = -1;
    for (pii pr : ranges) {
        int l, r;
        tie(l, r) = pr;
        if (l > prev) {
            res += l - prev - 1;
            prev = r;
        } else {
            maxi(prev, r);
        }
    }
    print(res);
}
