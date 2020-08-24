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
	
	int n, k;
	cin >> n >> k;
	vi a(n);
	cin >> a;


	vi mntree(2*n), mxtree(2*n);
	auto merge = [&](int x) {
		mntree[x] = min(mntree[2*x], mntree[2*x+1]);
		mxtree[x] = max(mxtree[2*x], mxtree[2*x+1]);
	};
	FOR(i, 0, n) mntree[n+i] = mxtree[n+i] = a[i];
	ROF(i, n-1, 0) merge(i);

	auto circle = [&](int l, int r) {
		l += n;
		r += n;
		vi res;
		while (l <= r) {
			if (l&1) res.push_back(l++);
			if (!(r&1)) res.push_back(r--);
			l /= 2;
			r /= 2;
		}
		return res;
	};

	auto mnquery = [&](int l, int r) {
		vi temp = circle(l, r);
		for (int &i : temp) i = mntree[i];
		return *min_element(ALL(temp));
	};

	auto mxquery = [&](int l, int r) {
		vi temp = circle(l, r);
		for (int &i : temp) i = mxtree[i];
		return *max_element(ALL(temp));
	};

	vpii mods(n-k+1);
	int x = n-k+1;
	ROF(l, n-k, -1) {
		int r = l+k-1;
		if (a[l] > mnquery(l+1, r)) x = l;
		else while (x < r && a[x] <= mnquery(x+1, r)) ++x;
		mods[l].first = x<r ? x : -1;
	}
	x = k-2;
	FOR(l, 0, n-k+1) {
		int r = l+k-1;
		if (a[r] < mxquery(l, r-1)) x = r;
		else while (x > l && a[x] >= mxquery(l, x-1)) --x;
		mods[l].second = x>l ? x : -1;
	}
	set<pii> modset;
	FOR(i, 0, n-k+1) modset.insert(mods[i]);
	print(SIZE(modset));
}