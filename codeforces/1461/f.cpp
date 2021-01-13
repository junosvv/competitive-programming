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

    string s;
    cin >> s;
    if (SIZE(s) == 1) {
        cout << a[0];
        FOR(i, 1, n) cout << s[0] << a[i];
        print();
    } else {
        bool mult = false, plus = false, minus = false;
        for (char c : s) {
            if (c == '*') mult = true;
            if (c == '+') plus = true;
            if (c == '-') minus = true;
        }
        if (!mult) {
            cout << a[0];
            FOR(i, 1, n) cout << '+' << a[i];
            print();
        } else if (!plus) {
            cout << a[0];
            bool split = false;
            FOR(i, 1, n) {
                if (split || a[i] != 0) cout << '*' << a[i];
                else {
                    cout << '-' << a[i];
                    split = true;
                }
            }
        } else {
            vvi subprobs;
            FOR(i, 0, n) {
                if (subprobs.empty() || (a[i] == 0) != (subprobs.back()[0] == 0)) {
                    subprobs.push_back({});
                }
                subprobs.back().push_back(a[i]);
            }

            FOR(t, 0, SIZE(subprobs)) {
                if (t) cout << '+';
                vi a = subprobs[t];
                int n = SIZE(a);
                if (a[0] == 0) {
                    cout << 0;
                    FOR(i, 1, n) cout << "+0";
                } else {
                    vi nodes;
                    vi edges = {0};
                    FOR(i, 0, n) {
                        if (a[i] == 1) {
                            edges.back() += 1;
                        } else {
                            nodes.push_back(a[i]);
                            edges.push_back(0);
                        }
                    }
                    int k = SIZE(nodes);
                    int res = edges.front() + edges.back();
                    if (k > 22) {
                        FOR(i, 0, k) {
                            FOR(j, 0, edges[i]) cout << 1 << (i ? '*' : '+');
                            cout << nodes[i];
                            if (i != k-1) cout << '*';
                        }
                        if (edges.back()) {
                            FOR(j, 0, edges.back()) cout << "+1";
                        }
                    } else {
                        vi dp(k+1);
                        vi par(k+1);
                        FOR(i, 1, k+1) {
                            int tk = 1;
                            ROF(j, i-1, -1) {
                                tk *= nodes[j];
                                if (maxi(dp[i], dp[j] + tk)) par[i] = j;
                            }
                            if (i != k) {
                                dp[i] += edges[i];
                            }
                        }
                        string s;
                        int x = k;
                        while (x) {
                            ROF(i, x, par[x]+1) {
                                FOR(j, 0, edges[i-1]+1) {
                                    s += '*';
                                }
                            }
                            x = par[x];
                            if (x) {
                                FOR(j, 0, edges[x]+1) {
                                    s += '+';
                                }
                            }
                        }
                        FOR(i, 0, edges.front()) s += '+';
                        reverse(ALL(s));
                        FOR(i, 0, edges.back()) s += '+';
                        cout << a[0];
                        FOR(i, 1, n) cout << s[i-1] << a[i];
                    }
                }
                // print();
            }
        }
    }
}

/*
22
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
+-*
*/