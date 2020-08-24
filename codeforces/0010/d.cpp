#include <bits/stdc++.h>
using namespace std;
 
#define lglg long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, b, a) for (int i=(b); i>(a); --i)
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
long long MOD = 998244353;

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
string bin_string(int x) {
    const int d = 32;
    string res(d, ' ');
    FOR(i, 0, d) res[d-1-i] = '0'+(x>>i & 1LL);
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

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int m;
    cin >> m;
    vi b(m);
    cin >> b;

    vi raw;
    set<int> temp;
    for (int i : a) temp.insert(i);
    for (int i : b) temp.insert(i);
    for (int i : temp) raw.push_back(i);
    int r = raw.size();
    mii trans;
    FOR(i, 0, r) trans[raw[i]] = i;
    for (int &i : a) i = trans[i];
    for (int &i : b) i = trans[i];

    vvi dp(n, vi(r+1));
    vector<vvb> par(n, vvb(m, vb(r+1)));
    FOR(j, 0, m) {
        vvi dp2(n, vi(r+1));
        vi occ(r, -1);
        FOR(i, 0, n) {
            occ[a[i]] = i;
            FOR(k, 0, r+1) {
                dp2[i][k] = j==0 ? 0 : dp[i][k];
                if (b[j] < k && occ[b[j]] != -1) {
                    int alt = 1 + (j==0 ? 0 : dp[occ[b[j]]][b[j]]);
                    if (alt > dp2[i][k]) {
                        par[i][j][k] = true;
                        dp2[i][k] = alt;
                    }
                }
            }
        }
        dp = dp2;
    }
    cout << dp[n-1][r] << '\n';
    int aa = n-1, bb = m-1, cc = r;
    vi res;
    while (aa >= 0 && bb >= 0 && cc > 0) {
        if (par[aa][bb][cc]) {
            res.push_back(bb);
            ROF(i, aa, -1) if (a[i] == b[bb]) {
                aa = i-1;
                break;
            }
            cc = b[bb];
        }
        --bb;
    }
    reverse(res.begin(), res.end());
    for (int i : res) cout << raw[b[i]] << ' ';
}