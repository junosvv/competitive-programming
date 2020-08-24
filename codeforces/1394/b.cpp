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
    
    const int BIG = 1000;
    vi sieve(BIG);
    vi primes;
    FOR(p, 2, BIG) {
        if (!sieve[p]) {
            if (p > 500) {
                primes.push_back(p);
            }
            for (int u=p*p; u<BIG; u+=p) {
                sieve[u] = p;
            }
        }
    }

    int p = primes[rand() % SIZE(primes)];

    int n, m, k;
    cin >> n >> m >> k;

    vi tk(n, 1);
    FOR(i, 1, n) {
        tk[i] = p * tk[i-1] % MOD;
    }

    vvpii nodes(n);

    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;

        nodes[u].emplace_back(w, v);
    }

    vvi cons(k, vi(k));
    FOR(u, 0, n) {
        sort(ALL(nodes[u]));

        FOR(i, 0, SIZE(nodes[u])) {
            int w, v;
            tie(w, v) = nodes[u][i];

            cons[SIZE(nodes[u]) - 1][i] = (cons[SIZE(nodes[u]) - 1][i] + tk[v]) % MOD;
        }
    }

    int want = 0;
    FOR(i, 0, n) {
        want = (want + tk[i]) % MOD;
    }
    
    vi perm(k, -1);
    int res = 0;
    function<void(int)> f = [&](int upto) {
        if (upto == k) {
            int cur = 0;
            FOR(i, 0, k) {
                cur = (cur + cons[i][perm[i]]) % MOD;
            }

            if (cur == want) {
                ++res;
                // FOR(i, 0, k) ++perm[i];
                // print(perm);
                // FOR(i, 0, k) --perm[i];
            }

            return;
        }

        FOR(i, 0, upto+1) {
            perm[upto] = i;
            f(upto+1);
        }
        perm[upto] = -1;
    };

    f(0);
    print(res);
}