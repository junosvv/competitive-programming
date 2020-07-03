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
#define vvpii vector<vpii>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SIZE(x) (signed)(x).size()
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
vi tree;
int m;
void merge(int x) {
    tree[x] = max(tree[2*x], tree[2*x+1]);
}

void upd(int x, int val) {
    // print("upd", x, ":", val);
    x += m;
    tree[x] = val;
    x /= 2;
    while (x) {
        merge(x);
        x /= 2;
    }
}

int get(int x) {
    return tree[x+m];
}

int query(int l, int r) {
    // print("query", l, r);
    int res = 0;
    l += m;
    r += m;
    while (l <= r) {
        if (l&1) maxi(res, tree[l++]);
        if (!(r&1)) maxi(res, tree[r--]);
        l /= 2;
        r /= 2;
    }
    return res;
}

vi dp, dp2;
vi memo;
vi a;
void dfs(int u, int p=-1) {
    memo[u] = get(a[u]);
    dp[u] = 1 + query(0, a[u] - 1);
    maxi(dp2[u], dp[u]);
    if (dp[u] > get(a[u])) upd(a[u], dp[u]);
    for (int v : nodes[u]) if (v != p) {
        maxi(dp2[v], dp2[u]);
        dfs(v, u);
    }
    upd(a[u], memo[u]);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    a.resize(n);
    cin >> a;
    mii trans;
    vi raw;
    set<int> seen;
    FOR(i, 0, n) {
        if (!seen.count(a[i])) {
            seen.insert(a[i]);
            raw.push_back(a[i]);
        }
    }
    sort(ALL(raw));
    m = SIZE(raw);
    FOR(i, 0, m) {
        trans[raw[i]] = i;
    }
    FOR(i, 0, n) a[i] = trans[a[i]];

    nodes.resize(n);
    FOR(i, 0, n-1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }

    tree.resize(2*m);
    dp.resize(n);
    dp2.resize(n);
    memo.resize(n);
    dfs(0);

    // print(a, raw, trans);
    FOR(i, 0, n) print(dp2[i]);
    // print(tree);
}

/*
7
1 2 3 4 6 6 7
1 2
2 3
3 4
2 5
5 6
6 7
*/