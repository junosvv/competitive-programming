#include <bits/stdc++.h>
using namespace std;
 
#define int long long
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
#define SQ(x) (x)*(x)
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
    void pr(bool x) { pr(x ? "true" : "false"); }
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

vvi nodes;
vi cols;
vi cnt(3);
void dfs(int u, int val, int p=-1) {
    cols[u] = val;
    ++cnt[val];
    for (int v : nodes[u]) if (v!=p) {
        dfs(v, 3-val, u);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    nodes.resize(n);
    cols.resize(n);
    FOR(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    dfs(0, 1);
    vi avail(3);
    FOR(i, 1, n+1) avail[i%3]++;
    
    vi revcnt = cnt;
    swap(revcnt[1], revcnt[2]);
    vi cnts = {3, 1, 2};
	if (avail[0] >= cnt[1]) {
		vb seen(n);
		FOR(i, 0, n) {
			if (cols[i] == 1) {
				seen[i] = true;
                cols[i] = cnts[0];
                cnts[0] += 3;
                --avail[0];
            }
		}
		FOR(i, 0, n) if (!seen[i]) {
			FOR(d, 0, 3) {
				if (avail[d]) {
					cols[i] = cnts[d];
					cnts[d] += 3;
					--avail[d];
					break;
				}
			}
		}
	} else if (avail[0] >= cnt[2]) {
		vb seen(n);
		FOR(i, 0, n) {
			if (cols[i] == 2) {
				seen[i] = true;
                cols[i] = cnts[0];
                cnts[0] += 3;
                --avail[0];
            }
		}
		FOR(i, 0, n) if (!seen[i]) {
			FOR(d, 0, 3) {
				if (avail[d]) {
					cols[i] = cnts[d];
					cnts[d] += 3;
					--avail[d];
					break;
				}
			}
		}
    } else if (cnt[1] >= avail[1] && cnt[2] >= avail[2]) {
        FOR(i, 0, n) {
            int x = cols[i];
            if (avail[x]) {
                cols[i] = cnts[x];
                cnts[x] += 3;
                --avail[x];
            } else {
                cols[i] = cnts[0];
                cnts[0] += 3;
                --avail[0];
            }
        }
    } else if (revcnt[1] >= avail[1] && revcnt[2] >= avail[2]) {
        FOR(i, 0, n) {
            if (cols[i]) cols[i] = 3-cols[i];
            int x = cols[i];
            if (avail[x]) {
                cols[i] = cnts[x];
                cnts[x] += 3;
                --avail[x];
            } else {
                cols[i] = cnts[0];
                cnts[0] += 3;
                --avail[0];
            }
        }
    } else {
		print(-1);
		exit(0);
	}
    FOR(i, 0, n) cout << cols[i] << ' ';
}