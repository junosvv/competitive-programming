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

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    CASET {
        int n, x;
        cin >> n >> x;
        vi pref(n);
        REP(i, 0, n) {
            char c;
            cin >> c;
            pref[i] = c=='1'?-1:1;
        }
        REP(i, 1, n) pref[i] += pref[i-1];

        mii occ;
        REP(i, 0, n) ++occ[pref[i]];
        
        int res = 0;
        if (x==0) ++res;
        if (pref.back() == 0) {
            if (occ[x]) cout << -1 << '\n';
            else cout << res << '\n';
        } else {
            if (pref.back() < 0) {
                REP(i, 0, pref.size()) pref[i] = -pref[i];
                mii occ0 = occ;
                occ.clear();
                for (auto &pr : occ0) occ[-pr.first] = pr.second;
                x = -x;
            }
            int offset = 0;
            int upp = 1e10;
            int mn = (*occ.begin()).first, mx = (*occ.rbegin()).first;
            for (int b=upp; b>=1; b/=2) {
                while (offset+b <= upp && x-(offset+b)*pref.back() >= mx) {
                    offset += b;
                }
            }

            offset *= pref.back();
            while (true) {
                if (occ.count(x-offset)) res += occ[x-offset];
                offset += pref.back();
                if (x-offset < mn) break;
            }
            cout << res << '\n';
        }
    }
}