#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define print(x) cout << to_string(x) << '\n'
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

string to_string(char &c) {string x(1, c); return x;}
string to_string(const char s[]) {return (string)s;}
string to_string(string &s) {return s;}
string to_string(vb &v) {string res; for (const bool &x : v) res += to_string(x) + ' '; return res;}
template <class C> string to_string(C &v) {string res; for (auto &x : v) res += to_string(x) + ' '; return res;}
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

int n;
vi cnt(26), fact, invfact;

int solve(string &u) {
    int res = 0;
    REP(x, 0, n) {
        int temp = 1;
        REP(c, 0, 26) temp = temp * invfact[cnt[c]] % MOD;
        temp = temp * fact[n-x-1] % MOD;

        REP(c, 0, 26) if (cnt[c] && c < u[x]-'a') {
            res = (res + temp*cnt[c]%MOD) % MOD;
        }
        if (cnt[u[x]-'a']) --cnt[u[x]-'a'];
        else break;
    }
    return res;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int BIG = 1e6+5;
    fact.assign(BIG, {});
    fact[0] = 1;
    REP(i, 1, BIG) fact[i] = fact[i-1] * i % MOD;
    invfact.assign(BIG, {});
    invfact[BIG-1] = inv(fact[BIG-1]);
    RREP(i, BIG-2, -1) invfact[i] = (i+1) * invfact[i+1] % MOD;

    string a, b;
    cin >> a >> b;
    n = a.size();

    REP(i, 0, n) ++cnt[a[i]-'a'];
    vi cnt0 = cnt;
    int res = solve(b);
    cnt = cnt0;
    res = (res-solve(a)-1+MOD+MOD) % MOD;
    print(res);
}