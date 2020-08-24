#include <bits/stdc++.h>
using namespace std;
 
#define lglg long long
#define dub long double
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define CASET int _T; cin >> _T; FOR(caset, 0, _T)
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
#define INV(x) powa(x, MOD-2)
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
 
main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int BIG = 1e6 + 5;
    vi sieve(BIG);
    for (int p=2; p*p<BIG; ++p) if (!sieve[p]) for (int u=p*p; u<BIG; u+=p) sieve[u] = p;

    vb isSquare(BIG);
    for (int i=0; i*i<BIG; ++i) isSquare[i*i] = true;

    int n;
    cin >> n;
    vvi nodes(BIG);
    vi a(n);
    cin >> a;
    for (int i : a) if (isSquare[i]) {
        print(1);
        exit(0);
    }

    set<pii> seen;
    FOR(i, 0, n) {
        int x = a[i];

        if (isSquare[x]) continue;
        
        mii factset;
        while (sieve[x]) {
            ++factset[sieve[x]];
            x /= sieve[x];
        }
        ++factset[x];

        vi facts;
        for (pii pr : factset) if (pr.second&1) facts.push_back(pr.first);
        if (SIZE(facts) == 1) {
            facts.push_back(facts[0]);
            facts[0] = 1;
        }
        assert(SIZE(facts) == 2);
        if (seen.count({facts[0], facts[1]})) {
            print(2);
            exit(0);
        }
        seen.insert({facts[0], facts[1]});
        nodes[facts[0]].push_back(facts[1]);
        nodes[facts[1]].push_back(facts[0]);
    }

    int res = 1e9;
    vi dist(BIG, -1);
    vi par(BIG, -1);
    for (int p=1; p*p<BIG; ++p) if (!sieve[p] && !nodes[p].empty()) {
        vi seen;
        deque<int> q = {p};
        dist[p] = 0;
        seen.push_back(p);
        while (!q.empty()) {
            int cur = q.front();
            q.pop_front();

            for (int nxt : nodes[cur]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    par[nxt] = cur;
                    seen.push_back(nxt);
                    q.push_back(nxt);
                } else if (par[nxt] != cur && par[cur] != nxt) {
                    mini(res, dist[cur] + dist[nxt] + 1);
                }
            }
        }
        for (int i : seen) dist[i] = par[i] = -1;
    }
    print(res==1e9 ? -1 : res);
}