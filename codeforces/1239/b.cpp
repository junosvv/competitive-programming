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

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi bal(n);
    int cleft=0, cright=0;
    FOR(i, 0, n) {
        char x;
        cin >> x;
        if (x == '(') {
            bal[i] = 1;
            ++cleft;
        } else {
            bal[i] = -1;
            ++cright;
        }
    }
    if (cleft != cright) {
        cout << "0\n1 1";
        exit(0);
    }
    FOR(i, 1, n) bal[i] += bal[i-1];
    int temp = *min_element(bal.begin(), bal.end());
    FOR(i, 0, n) bal[i] -= temp;
    vi occ0, occ01;
    FOR(i, 0, n) {
        if (bal[i] == 0) {
            occ0.push_back(i);
            occ01.push_back(i);
        } else if (bal[i] == 1) occ01.push_back(i);
    }

    int res = occ0.size();
    int ansA=0, ansB=0;
    auto check = [&](int cur, int a, int b) {
        if (cur > res) {
            res = cur;
            ansA = a;
            ansB = b;
        }
    };
    int cur = 0;
    FOR(i, 0, occ0[0]) if (bal[i] == 1) ++cur;
    FOR(i, occ0.back()+1, n) if (bal[i] == 1) ++cur;
    check(cur, (occ0.back()+1)%n, occ0[0]);
    FOR(j, 1, occ0.size()) {
        cur = 0;
        FOR(i, occ0[j-1]+1, occ0[j]) if (bal[i] == 1) ++cur;
        check(cur, occ0[j-1]+1, occ0[j]);
    }

    cur = occ0.size();
    FOR(i, 0, occ01[0]) if (bal[i] == 2) ++cur;
    FOR(i, occ01.back()+1, n) if (bal[i] == 2) ++cur;
    check(cur, (occ01.back()+1)%n, occ01[0]);
    FOR(j, 1, occ01.size()) {
        cur = occ0.size();
        FOR(i, occ01[j-1]+1, occ01[j]) if (bal[i] == 2) ++cur;
        check(cur, occ01[j-1]+1, occ01[j]);
    }
    cout << res << '\n' << ansA+1 << ' ' << ansB+1;
}