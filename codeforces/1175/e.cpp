#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, b, a) for (int i=(b); i>(a); --i)
#define CASET int _T; cin >> _T; FOR(caset, 0, _T)
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define mii map<int,int>
#define vpii vector<pii>
#define vt3i vector<t3i>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)
 
long long INF = 1LL<<60;
long long MOD = 1e9+7;

template <typename A, typename B> istream &operator>>(istream &is, pair<A, B> &pr) {is >> pr.first >> pr.second; return is;}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {for (auto &x : v) is >> x; return is;}
ostream &operator<<(ostream &os, char &c) {os << (char)c; return os;}
ostream &operator<<(ostream &os, const char s[]) {os << (string)s; return os;}
ostream &operator<<(ostream &os, string &s) {for (char &c : s) os << (char)c; return os;}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> &pr) {os << '(' << pr.first << ", " << pr.second << ')'; return os;}
ostream &operator<<(ostream &os, vb &v) {
    bool first = true;
    os << '[';
    for (const bool &x : v) {
        if (!first) os << ", ";
        first = false;
        os << x;
    }
    os << ']';
    return os;
}
template <class C> ostream &operator<<(ostream &os, C &v) {
    bool first = true;
    os << '[';
    for (auto &x : v) {
        if (!first) os << ", ";
        first = false;
        os << x;
    }
    os << ']';
    return os;
}
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vpii intervals(n);
	vpii events;
	FOR(i, 0, n) {
		cin >> intervals[i].first >> intervals[i].second;
		events.push_back({intervals[i].first, 0});
		events.push_back({intervals[i].second, 1});
	}
	sort(events.begin(), events.end());

	const int BIG = 5e5+5;
	vi leftcomp(BIG, -1), rightcomp(BIG, -1);
	int cntactive = 0;
	int lefti = 0;
	for (pii ev : events) {
		int t, delet;
		tie(t, delet) = ev;
		if (delet) {
			--cntactive;
			if (cntactive == 0) {
				FOR(i, lefti, t+1) {
					leftcomp[i] = lefti;
					rightcomp[i] = t;
				}
			}
		} else {
			++cntactive;
			if (cntactive == 1) {
				lefti = t;
			}
		}
	}

	int K = 25;
	vvi jumpto(K, vi(BIG));
	FOR(i, 0, n) jumpto[0][intervals[i].first] = max(jumpto[0][intervals[i].first], intervals[i].second);
	FOR(i, 1, BIG) jumpto[0][i] = max(jumpto[0][i], jumpto[0][i-1]);
	FOR(k, 1, K) FOR(i, 0, BIG) jumpto[k][i] = jumpto[k-1][jumpto[k-1][i]];
	
	vi dpright(BIG, -1);
	ROF(i, BIG-1, -1) {
		if (rightcomp[i] == -1) continue;
		if (rightcomp[i] == i) dpright[i] = 0;
		else dpright[i] = 1 + dpright[jumpto[0][i]];
	}

	FOR(_, 0, m) {
		int a, b;
		cin >> a >> b;
		if (leftcomp[a] != leftcomp[b] || leftcomp[a] == -1) {
			cout << -1 << '\n';
			continue;
		}
		int res = 0;
		int at = a;
		ROF(k, 24, -1) {
			if (jumpto[k][at] < b) {
				at = jumpto[k][at];
				res += 1<<k;
			}
		}
		cout << res+1 << '\n';
	}
}