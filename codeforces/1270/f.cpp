#include <bits/stdc++.h>
using namespace std;

#define lglg long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define print(x) cout << to_string(x) << '\n'
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define mii map<int,int>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)

int INF = 1LL<<60;
int MOD = 998244353;

string to_string(string &s) {return s;}
string to_string(const char s[]) {return (string)s;}
template <class C> string to_string(C &v) {
    string res;
    for (auto &x : v) res += to_string(x) + ' ';
    return res;
}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {
    for (auto &x : v) is >> x;
    return is;
}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> pr) {
    os << '(' << pr.first << ", " << pr.second << ')';
    return os;
}
ostream &operator<<(ostream &os, string &s) {for (char &c : s) os << (char)c; return os;}
ostream &operator<<(ostream &os, const char s[]) {os << (string)s; return os;}
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    vb arr(n+1); REP(i, 0, n) arr[i+1] = s[i]-'0';
    vi pref(n+1); REP(i, 1, n+1) pref[i] = pref[i-1] + arr[i];
    vi loc(pref[n]+1);
    RREP(i, n, 0) loc[pref[i]] = i;

    const int B = sqrt(n)+1;

    lglg res = 0;
    vi occ(B*n+1);
    REP(k, 1, B+1) {
        REP(i, 0, n+1) res += occ[n-i+k*pref[i]]++;
        REP(i, 0, n+1) occ[n-i+k*pref[i]] = 0;
    }
    
    lglg res2 = 0;
    REP(l, 0, n) {
        REP(w, 1, B+1) {
            if (pref[l]+w > pref[n]) break;
            int left = loc[pref[l]+w];
            int right = (pref[l]+w+1 > pref[n]) ? n : loc[pref[l]+w+1]-1;
            int r = l+(B+1)*w;
            if (r > right) continue;
            res2 += (right-r)/w + 1 - max(0, (left-r-1+w)/w);
        }
    }
    cout << res+res2 << endl;
}