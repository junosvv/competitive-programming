#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
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
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> pr) {os << '(' << pr.first << ", " << pr.second << ')'; return os;}
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
string bin_string(int x) {
    const int d = 32;
    string res(d, ' ');
    REP(i, 0, d) res[d-1-i] = '0'+(x>>i & 1LL);
    return res;
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

int sz;
vi a, sum, pref;
void merge(int x) {
    sum[x] = sum[2*x] + sum[2*x+1];
    pref[x] = min(pref[2*x], sum[2*x] + pref[2*x+1]);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    sz = 1;
    while (sz<n-1) sz *= 2;
    a.resize(n);
    sum.resize(2*sz);
    pref.resize(2*sz);
    
    vi pos(n+1);
    REP(i, 0, n) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    vi cost(n);
    cin >> cost;
    REP(i, 0, n-1) sum[sz+i] = pref[sz+i] = cost[i];
    RREP(i, sz-1, 0) merge(i);

    int osum = 0;
    int res = INF;
    REP(k, 0, n+1) {
        if (k!=0) {
            osum += cost[pos[k]];
            if (pos[k] != n-1) {
                int x = sz + pos[k];
                sum[x] *= -1;
                pref[x] *= -1;
                x /= 2;
                while (x) {
                    merge(x);
                    x /= 2;
                }
            }
        }
        res = min(res, osum+pref[1]);
    }
    cout << res;
}