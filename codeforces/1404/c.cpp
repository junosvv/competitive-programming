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

vi tree, lazy;
int n;
void inc(int x, int delta) {
    tree[x] += delta;
    if (x < n) lazy[x] += delta;
}

void fix(int x) {
    while (x) {
        tree[x] = max(tree[2*x], tree[2*x+1]) + lazy[x];
        x /= 2;
    }
}

void upd(int l, int r, int delta) {
    l += n;
    r += n;
    int l0 = l;
    int r0 = r;
    while (l <= r) {
        if (l&1) inc(l++, delta);
        if (!(r&1)) inc(r--, delta);
        l /= 2;
        r /= 2;
    }
    fix(l0/2);
    fix(r0/2);
}

int qfind(int x) {
    int node = 1;
    while (node < n) {
        inc(2*node, lazy[node]);
        inc(2*node+1, lazy[node]);
        lazy[node] = 0;
        if (tree[2*node+1] < x) node = 2*node;
        else node = 2*node + 1;
    }
    return node-n;
}

vi sumtree;
int sumquery(int l, int r) {
    l += n;
    r += n;
    int res = 0;
    while (l <= r) {
        if (l&1) res += sumtree[l++];
        if (!(r&1)) res += sumtree[r--];
        l /= 2;
        r /= 2;
    }
    return res;
}

void sumupd(int x, int delta) {
    x += n;
    sumtree[x] += delta;
    x /= 2;
    while (x) {
        sumtree[x] = sumtree[2*x] + sumtree[2*x+1];
        x /= 2;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int q;
    cin >> n >> q;
    vi a(n);
    cin >> a;

    vt3i queries(q);
    FOR(qi, 0, q) {
        int l, r;
        cin >> l >> r;
        r = n-1-r;
        queries[qi] = {l, r, qi};
    }
    sort(RALL(queries));

    FOR(i, 0, n) a[i] = i+1 - a[i];

    n = 1;
    while (n < SIZE(a)) n *= 2;
    a.resize(n, -1);

    tree.resize(2*n);
    lazy.resize(n);

    vi left(n, -1);
    
    FOR(i, 0, n) {
        if (a[i] < 0 || a[i] > tree[1]) {
            continue;
        }
        if (a[i] == 0) {
            upd(0, i, 1);
            left[i] = i;
            continue;
        }
        assert(i != 0);
        int x = qfind(a[i]);
        if (x >= i) x = i-1;
        left[i] = x;
        upd(0, x, 1);
    }

    vvi occ(n);
    FOR(i, 0, n) if (left[i] != -1) {
        occ[left[i]].push_back(i);
    }

    sumtree.resize(2*n);
    vi res(q);
    int cnt = n-1;
    for (t3i tup : queries) {
        int l, r, qi;
        tie(l, r, qi) = tup;

        while (cnt >= l) {
            for (int u : occ[cnt]) {
                sumupd(u, 1);
            }
            --cnt;
        }
        res[qi] = sumquery(l, r);
    }
    
    FOR(i, 0, q) {
        print(res[i]);
    }
}
