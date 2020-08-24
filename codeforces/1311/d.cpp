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

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    CASET {
        vi a(3);
        // a = {9989, 9988, 9868};
        cin >> a;

        int BIG = 2e4+5;
        vi secondlast(BIG, 1e8);
        vi par(BIG);
        vi mult(BIG, 1e9);
        vi multpar(BIG);
        FOR(i, 1, BIG) {
            for (int opt : vi{a[2]/i*i-i, a[2]/i*i, a[2]/i*i+i, a[2]/i*i+i+i}) if (0 <= opt && opt < BIG) {
                if (mini(secondlast[i], abs(i-a[1]) + abs(opt-a[2]))) par[i] = opt;
            }
            for (int d=1; d*d<=i; ++d) {
                if (i%d==0) {
                    if (mini(mult[d], secondlast[i])) multpar[d] = i;
                    if (mini(mult[i/d], secondlast[i])) multpar[i/d] = i;
                }
            }
        }

        int res = 1e9;
        int resA = -1, resB, resC;
        FOR(i, 1, BIG) {
            if (mini(res, abs(i-a[0]) + mult[i])) {
                resA = i;
                resB = multpar[i];
                resC = par[multpar[i]];
            }
        }
        cout << res << '\n' << resA << ' ' << resB << ' ' << resC << '\n';
    }
    // cout << "done" << endl;
}