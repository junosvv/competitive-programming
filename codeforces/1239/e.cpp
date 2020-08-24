#include <bits/stdc++.h>
using namespace std;
 
#define lglg long long
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

    int n;
    cin >> n;
    vi a(2*n);
    cin >> a;
    sort(a.rbegin(), a.rend());

    vi log(1<<n);
    FOR(i, 2, 1<<n) log[i] = 1 + log[i/2];

    int mnA = a.back();
    a.pop_back();
    int mnB = a.back();
    a.pop_back();
    --n;

    const int BIG = 24 * 50000 + 1;
    vvi lft(n+1, vi(BIG, -1)), rgt(n+1, vi(BIG, -1));
    vi dpsum(1<<n);
    lft[0][0] = rgt[0][0] = 0;
    FOR(mask, 1, 1<<n) {
        dpsum[mask] = a[log[mask]] + dpsum[mask - (1<<log[mask])];
        lft[__builtin_popcountll(mask)][dpsum[mask]] = mask;
    }

    dpsum.assign(1<<n, 0);
    FOR(mask, 1, 1<<n) {
        dpsum[mask] = a[n+log[mask]] + dpsum[mask - (1<<log[mask])];
        rgt[__builtin_popcountll(mask)][dpsum[mask]] = mask;
    }

    int sum = accumulate(a.begin(), a.end(), 0LL);
    int halfsum = sum / 2;
    int res = -1;
    int maskA, maskB;
    FOR(sz, 0, n+1) {
        vi vecA, vecB;
        FOR(i, 0, BIG) if (lft[sz][i] != -1) vecA.push_back(i);
        FOR(i, 0, BIG) if (rgt[n-sz][i] != -1) vecB.push_back(i);
        int i = 0;
        int j = vecB.size() - 1;
        while (i < vecA.size() && j >= 0) {
            if (vecA[i] + vecB[j] > halfsum) --j;
            else {
                if (vecA[i]+vecB[j] > res) {
                    res = vecA[i]+vecB[j];
                    maskA = lft[sz][vecA[i]];
                    maskB = rgt[n-sz][vecB[j]];
                }
                res = max(res, vecA[i] + vecB[j]);
                ++i;
            }
        }
    }
    vi top = {mnA};
    vi bottom;
    FOR(i, 0, n) {
        if (maskA>>i&1LL) top.push_back(a[i]);
        else bottom.push_back(a[i]);
    }
    FOR(i, 0, n) {
        if (maskB>>i&1LL) top.push_back(a[n+i]);
        else bottom.push_back(a[n+i]);
    }
    bottom.push_back(mnB);
    sort(top.begin(), top.end());
    sort(bottom.rbegin(), bottom.rend());
    FOR(i, 0, n+1) cout << top[i] << ' ';
    cout << '\n';
    FOR(i, 0, n+1) cout << bottom[i] << ' ';
}