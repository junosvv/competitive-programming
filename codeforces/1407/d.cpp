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
    set<int> raw;
    mii trans;
    FOR(i, 0, n) {
        cin >> a[i];
        raw.insert(a[i]);
    }
    int m = 0;
    for (int i : raw) {
        trans[i] = m;
        ++m;
    }
    FOR(i, 0, n) {
        a[i] = trans[a[i]];
    }

    vi tree(2*m);
    
    auto upd = [&](int x, int delta) {
        x += m;
        tree[x] = delta;
        x /= 2;
        while (x) {
            tree[x] = max(tree[2*x], tree[2*x+1]);
            x /= 2;
        }
    };

    auto query = [&](int l, int r) {
        l += m;
        r += m;
        int res = 0;
        while (l <= r) {
            if (l&1) maxi(res, tree[l++]);
            if (!(r&1)) maxi(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    };

    vi nextlt(n), nextgt(n);
    FOR(i, 0, n) {
        nextlt[i] = query(0, a[i]);
        nextgt[i] = query(a[i], m-1);
        upd(a[i], i);
    }

    vi dp(n, INF);
    dp[0] = 0;
    vi bigdptree(2*n, INF), smaldptree(2*n, INF);
    auto dpupd = [&](vi &tree, int x, int val) {
        x += n;
        tree[x] = val;
        x /= 2;
        while (x) {
            tree[x] = min(tree[2*x], tree[2*x+1]);
            x /= 2;
        }
    };

    auto dpquery = [&](vi &tree, int l, int r) {
        l += n;
        r += n;
        int res = INF;
        while (l <= r) {
            if (l&1) mini(res, tree[l++]);
            if (!(r&1)) mini(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    };

    // print("HERE", a, nextlt, nextgt);

    vpii bigsuf, smalsuf;
    FOR(i, 0, n) {
        if (i) {
            if (a[i-1] < a[i]) {
                dp[i] = 1 + dpquery(bigdptree, nextgt[i], n-1);
            } else if (a[i-1] > a[i]) {
                dp[i] = 1 + dpquery(smaldptree, nextlt[i], n-1);
            } else {
                dp[i] = 1 + dp[i-1];
            }
        }
        mini(dp[i], 1 + dp[i-1]);

        while (!bigsuf.empty() && bigsuf.back().second <= a[i]) {
            dpupd(bigdptree, bigsuf.back().first, INF);
            bigsuf.pop_back();
        }
        bigsuf.emplace_back(i, a[i]);
        dpupd(bigdptree, i, dp[i]);
        while (!smalsuf.empty() && smalsuf.back().second >= a[i]) {
            dpupd(smaldptree, smalsuf.back().first, INF);
            smalsuf.pop_back();
        }
        smalsuf.emplace_back(i, a[i]);
        dpupd(smaldptree, i, dp[i]);
    }
    print(dp.back());
    // print(dp);
}
