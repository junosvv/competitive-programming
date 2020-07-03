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

    vi sdp(n, 1);
    FOR(k, 1, n) {
        FOR(i, 0, k) {
            if (a[i]%7==a[k]%7 || abs(a[i]-a[k]) == 1) {
                sdp[k] = max(sdp[k], sdp[i]+1);
            }
        }
    }

    int BIG = 1e5+5;
    vvi occ(BIG);
    FOR(i, 0, n) occ[a[i]].push_back(i);

    vvi dp(n, vi(n));
    vvi maxs(7, vi(n));

    FOR(k, 1, n) {
        FOR(i, 0, k) {
            dp[k][i] = max(sdp[i]+1, maxs[a[k]%7][i]+1);
            for (int alt : vi{a[k]-1, a[k]+1}) {
                int kk = -1;
                int upp = occ[alt].size();
                for (int bb=upp; bb>=1; bb/=2) {
                    while (kk+bb < upp && occ[alt][kk+bb] < k) kk += bb;
                }
                if (kk != -1) {
                    int j = occ[alt][kk];
                    if (j == i) --kk;
                    if (kk != -1) {
                        j = occ[alt][kk];
                        dp[k][i] = max(dp[k][i], dp[i][j]+1);
                    }
                }
            }
            dp[i][k] = dp[k][i];
            maxs[a[k]%7][i] = max(maxs[a[k]%7][i], dp[i][k]);
            maxs[a[i]%7][k] = max(maxs[a[i]%7][k], dp[k][i]);
        }
    }
    int mx = 0;
    FOR(i, 0, n) FOR(j, 0, n) mx = max(mx, dp[i][j]);
    cout << mx << '\n';
    // cout << dp << '\n';
}

// [[0, 2, 2, 3, 2, 3], [2, 0, 2, 3, 3, 4], [2, 2, 0, 3, 3, 4], [3, 3, 3, 0, 4, 5], [2, 3, 3, 4, 0, 3], [3, 4, 4, 5, 3, 0]]