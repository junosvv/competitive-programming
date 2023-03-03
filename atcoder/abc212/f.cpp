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
long long MOD = 998244353;
 
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
    
    int n, m, q;
    cin >> n >> m >> q;

    vvi edges(m, vi(4));
    FOR(i, 0, m) {
        cin >> edges[i];
        --edges[i][0], --edges[i][1];
        swap(edges[i][0], edges[i][2]);
        edges[i][0] *= -1;
    }
    sort(ALL(edges));
    FOR(i, 0, m) {
        edges[i][0] *= -1;
        swap(edges[i][0], edges[i][2]);
    }

    const int UPNUM = 18;
    vvi up(n, vi(UPNUM));
    FOR(i, 0, n) up[i][0] = i;

    vi city(n);
    FOR(i, 0, n) city[i] = i;
    vi time(n, INF);
    vvpii nodes(n);
    FOR(i, 0, n) nodes[i] = {{INF, i}};
    vi edgeid(n, -1);

    FOR(i, 0, m) {
        int a=edges[i][0], b=edges[i][1], s=edges[i][2], t=edges[i][3];

        nodes[a].emplace_back(s, SIZE(city));
        city.push_back(a);
        time.push_back(s);
        edgeid.push_back(i);
        int kk = -1;
        int upp = SIZE(nodes[b]);
        for (int bb=upp; bb>=1; bb/=2) {
            while (kk+bb<upp && nodes[b][kk+bb].first >= t) kk += bb;
        }
        up.push_back(vi(UPNUM));
        up.back()[0] = nodes[b][kk].second;
    }

    int sz = SIZE(city);
    FOR(k, 1, UPNUM) {
        FOR(u, 0, sz) {
            up[u][k] = up[up[u][k-1]][k-1];
        }
    }

    FOR(qi, 0, q) {
        int start, a, endt;
        cin >> start >> a >> endt;
        --a;

        int kk = -1;
        int upp = SIZE(nodes[a]);
        for (int bb=upp; bb>=1; bb/=2) {
            while (kk+bb<upp && nodes[a][kk+bb].first >= start) kk += bb;
        }
        int id = nodes[a][kk].second;
        
        for (int b=UPNUM-1; b>=0; --b) {
            while (time[up[id][b]] < endt) id = up[id][b];
        }

        if (edgeid[id] != -1) {
            if (endt > edges[edgeid[id]][3]) {
                id = up[id][0];
                print(city[id] + 1);
            } else if (endt > edges[edgeid[id]][2]) {
                print(edges[edgeid[id]][0]+1, edges[edgeid[id]][1]+1);
            } else {
                print(city[id] + 1);
            }
        } else {
            print(city[id] + 1);
        }
    }
}