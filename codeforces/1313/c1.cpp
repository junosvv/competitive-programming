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
bool mini(int &a, int b) { return b < a ? a = b, 1 : 0; }
bool maxi(int &a, int b) { return b > a ? a = b, 1 : 0; }

// al-cash
void calc(int n, vi &t, vi &d, int p, int k) {
  if (d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
  else t[p] = d[p] * k;
}

void apply(int n, vi &t, vi &d, int p, int value, int k) {
  t[p] = value * k;
  if (p < n) d[p] = value;
}

void build(int n, vi &t, vi &d, int l, int r) {
  int k = 2;
  for (l += n, r += n-1; l > 1; k <<= 1) {
    l >>= 1, r >>= 1;
    for (int i = r; i >= l; --i) calc(n, t, d, i, k);
  }
}

int h = 30;
void push(int n, vi &t, vi &d, int l, int r) {
  int s = h, k = 1 << (h-1);
  for (l += n, r += n-1; s > 0; --s, k >>= 1)
    for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
      apply(n, t, d, i<<1, d[i], k);
      apply(n, t, d, i<<1|1, d[i], k);
      d[i] = 0;
    }
}

void modify(int n, vi &t, vi &d, int l, int r, int value) {
  if (value == 0) return;
  push(n, t, d, l, l + 1);
  push(n, t, d, r - 1, r);
  int l0 = l, r0 = r, k = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l&1) apply(n, t, d, l++, value, k);
    if (r&1) apply(n, t, d, --r, value, k);
  }
  build(n, t, d, l0, l0 + 1);
  build(n, t, d, r0 - 1, r0);
}

int query(int n, vi &t, vi &d, int l, int r) {
  push(n, t, d, l, l + 1);
  push(n, t, d, r - 1, r);
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    set<int> valset;
    vi vals;
    mii compr;
    vi a(n);
    FOR(i, 0, n) {
        cin >> a[i];
        valset.insert(a[i]);
    }
    for (int i : valset) {
        compr[i] = vals.size();
        vals.push_back(i);
    }
    int m = vals.size();
    FOR(i, 0, n) a[i] = compr[a[i]];
    
    vi sumtree(2*n), sumlazy(n), loctree(2*m), loclazy(m);

    vi scores(n);
    FOR(i, 0, n) {
        int x;
        if (a[i] == 0) x = 0;
        else x = query(m, loctree, loclazy, a[i]-1, a[i]);
        modify(n, sumtree, sumlazy, x, n, vals[a[i]]);
        modify(m, loctree, loclazy, a[i], m, i+1);
        scores[i] = query(n, sumtree, sumlazy, 0, i+1);
    }
    sumtree.assign(2*n, {});
    sumlazy.assign(n, {});
    loctree.assign(2*m, {});
    loclazy.assign(m, {});
    reverse(a.begin(), a.end());

    vi scores2(n);
    FOR(i, 0, n) {
        int x;
        if (a[i] == 0) x = 0;
        else x = query(m, loctree, loclazy, a[i]-1, a[i]);
        modify(n, sumtree, sumlazy, x, n, vals[a[i]]);
        modify(m, loctree, loclazy, a[i], m, i+1);
        scores2[n-1-i] += query(n, sumtree, sumlazy, 0, i+1);
    }

    reverse(a.begin(), a.end());
    vi finals(n);
    FOR(i, 0, n) finals[i] = scores[i] + scores2[i] - vals[a[i]];
    
    int best = max_element(finals.begin(), finals.end()) - finals.begin();

    FOR(i, 0, n) a[i] = vals[a[i]];
    vi cur(n);
    cur[best] = a[best];
    FOR(j, best+1, n) {
        cur[j] = min(cur[j-1], a[j]);
    }
    ROF(j, best-1, -1) {
        cur[j] = min(cur[j+1], a[j]);
    }
    FOR(i, 0, cur.size()) cout << cur[i] << ' ';
}