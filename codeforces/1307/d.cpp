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
	
	int n, m, sn;
	cin >> n >> m >> sn;
	vi spec(sn);
	FOR(i, 0, sn) {
		cin >> spec[i];
		--spec[i];
	}
	vvi nodes(n);
	FOR(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	auto bfs = [&](vi &dist, int x) {
		queue<int> q;
		q.push(x);
		while (q.size()) {
			int cur = q.front();
			q.pop();

			for (int v : nodes[cur]) if (dist[v] == -1) {
				dist[v] = dist[cur] + 1;
				q.push(v);
			}
		}
	};

	vi dist1(n, -1), distn(n, -1);
	dist1[0] = 0;
	distn[n-1] = 0;
	bfs(dist1, 0);
	bfs(distn, n-1);

	vvi cangetocc(n);
	for (int i : spec) {
		cangetocc[dist1[i]].push_back(distn[i]);
	}
	FOR(i, 0, n) sort(cangetocc[i].rbegin(), cangetocc[i].rend());
	
	vi canget(2*n, -INF), canget1(n, -INF), canget2(n, -INF);
	FOR(i, 0, n) {
		if (cangetocc[i].size() >= 1) canget[n+i] = canget1[i] = cangetocc[i][0];
		if (cangetocc[i].size() >= 2) canget2[i] = cangetocc[i][1];
	}

	auto merge = [&](int x) {
		canget[x] = max(canget[2*x], canget[2*x+1]);
	};

	auto upd = [&](int x, int val) {
		x += n;
		canget[x] = val;
		x /= 2;
		while (x) {
			merge(x);
			x /= 2;
		}
	};

	ROF(i, n-1, 0) merge(i);

	auto query = [&](int l, int r) {
		l += n;
		r += n;
		int res = -INF;
		while (l <= r) {
			if (l&1) res = max(res, canget[l++]);
			if (!(r&1)) res = max(res, canget[r--]);
			l /= 2;
			r /= 2;
		}
		return res;
	};

	auto check = [&](int top, int bottom, int k) {
		int needtop = k-bottom-1;
		int needbottom = k-top-1;
		needtop = max(needtop, 0LL);
		int best = query(needtop, n-1);
		return best >= needbottom;
	};

	int orig = distn[0];
	int res = 0;
	for (int i : spec) {
		int top = dist1[i];
		int bottom = distn[i];
		if (bottom == canget[n+top]) {
			upd(top, canget2[top]);
		}
		int k = 0;
		for (int b=orig; b>=1; b/=2) {
			while (k+b <= orig) {
				if (!check(top, bottom, k+b)) break;
				k += b;
			}
		}
		res = max(res, k);
		upd(top, canget1[top]);
	}
	cout << res << '\n';
}

/*
9 9 3
1 3 9
1 2
2 3
3 4
4 9
1 5
5 6
6 7
7 8
8 9
*/