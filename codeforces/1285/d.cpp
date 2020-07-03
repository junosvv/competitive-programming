#include <bits/stdc++.h>
using namespace std;

#define int long long
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define print(x) cout << to_string(x) << ' '
#define println(x) cout << to_string(x) << '\n'
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)

int INF = 1LL<<60;
int MOD = 998244353;

string to_string(string &s) {return s;}
string to_string(const char s[]) {return (string)s;}
template <class C> string to_string(C &v) {
    string res;
    for (auto &i : v) res += to_string(i) + ' ';
    return res; 
}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {for (auto &x : v) is >> x; return is;}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> &v);
template <typename A> ostream &operator<<(ostream &os, vector<A> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A> ostream &operator<<(ostream &os, set<A> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A> ostream &operator<<(ostream &os, multiset<A> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A, typename B> ostream &operator<<(ostream &os, map<A,B> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> &pr) {os << '(' << pr.first << ", " << pr.second << ')';}
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
vi a;
int solve(int l, int r, int c) {
    if (c==-1) return 0;
    int res = 0;
    if (!(a[l]>>c&1LL) && (a[r]>>c&1LL)) {
        res += 1LL<<c;
        int k=l; while(!(a[k]>>c&1LL)) ++k;
        res += min(solve(l, k-1, c-1), solve(k, r, c-1));
    } else {
        res = solve(l, r, c-1);
    }
    return res;
}
 
main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    a.resize(n);
    cin >> a;
    sort(a.begin(), a.end());
 
    cout << solve(0, n-1, 40);
}