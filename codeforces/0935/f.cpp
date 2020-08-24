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

int n, m;
vi smtree;
vpii mntree, mxtree;
vb ortree;
void merge(int x) {
    mntree[x] = min(mntree[2*x], mntree[2*x+1]);
    mxtree[x] = max(mxtree[2*x], mxtree[2*x+1]);
    smtree[x] = abs(smtree[2*x]) + abs(smtree[2*x+1]);
}

void updor(int x) {
    if (x < 0 || x >= m) return;
    ortree[x+m] = smtree[x+n] >= 0 && smtree[x+n+1] <= 0;
    x += m;
    x /= 2;
    while (x) {
        ortree[x] = ortree[2*x] | ortree[2*x+1];
        x /= 2;
    }
}

void upd(int x, int delta) {
    int x0 = x;
    x += n;
    smtree[x] += delta;
    mntree[x].first = smtree[x] < 0 ? INF : smtree[x];
    mxtree[x].first = smtree[x] > 0 ? -INF : smtree[x];
    mntree[x].second = mxtree[x].second = x-n;
    x /= 2;
    while (x) {
        merge(x);
        x /= 2;
    }
    updor(x0-1);
    updor(x0);
}

vi circle(int l, int r) {
    vi res;
    l += n;
    r += n;
    while (l <= r) {
        if (l&1) res.push_back(l++);
        if (!(r&1)) res.push_back(r--);
        l /= 2;
        r /= 2;
    }
    return res;
}

bool orquery(int l, int r) {
    bool res = false;
    l += m;
    r += m;
    while (l <= r) {
        if (l&1) res |= ortree[l++];
        if (!(r&1)) res |= ortree[r--];
        l /= 2;
        r /= 2;
    }
    return res;
}

int eff(int x, int delta) {
    if (x == 0) return 0;
    return abs(smtree[n+x] + delta) - abs(smtree[n+x]);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    m = n-1;
    mntree.resize(2*n);
    mxtree.resize(2*n);
    smtree.resize(2*n);
    REP(i, 0, n) cin >> smtree[n+i];
    RREP(i, n-1, 0) smtree[n+i] -= smtree[n+i-1];
    REP(i, n, 2*n) {
        mntree[i].first = smtree[i] < 0 ? INF : smtree[i];
        mxtree[i].first = smtree[i] > 0 ? -INF : smtree[i];
        mntree[i].second = mxtree[i].second = i-n;
    }
    RREP(i, n-1, 0) merge(i);

    ortree.resize(2*m);
    REP(i, 0, m) ortree[m+i] = smtree[n+i] >= 0 && smtree[n+i+1] <= 0;
    RREP(i, m-1, 0) ortree[i] = ortree[2*i] | ortree[2*i+1];

    int nq;
    cin >> nq;
    REP(q, 0, nq) {
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        --l; --r;
        if (t == 1) {
            int sm = smtree[1] - smtree[n];
            int ex = eff(l, x) + eff(l+1, -x);
            if (r == n-1) {
                ex = max(ex, eff(r, x));
                --r;
            }
            if (orquery(l, r)) ex = 2*x;
            else {
                pii mn = {INF, INF}, mx = {-INF, -INF};
                for (int i : circle(l+1, r+1)) mn = min(mn, mntree[i]);
                for (int i : circle(l, r)) mx = max(mx, mxtree[i]);
                if (mn.first != INF) {
                    if (smtree[n+mn.second-1] < 0) {
                        ex = max(ex, eff(mn.second-1, x) + eff(mn.second, -x));
                        int newl = mn.second+1;
                        mn = {INF, INF};
                        for (int i : circle(newl, r+1)) mn = min(mn, mntree[i]);
                    }
                    if (mn.first != INF) ex = max(ex, eff(mn.second-1, x) + eff(mn.second, -x));
                }
                if (mx.first != -INF) {
                    if (smtree[n+mx.second+1] > 0) {
                        ex = max(ex, eff(mx.second, x) + eff(mx.second+1, -x));
                        int newr = mx.second-1;
                        mx = {-INF, -INF};
                        for (int i : circle(l, newr)) mx = max(mx, mxtree[i]);
                    }
                    if (mx.first != -INF) ex = max(ex, eff(mx.second, x) + eff(mx.second+1, -x));
                }
            }
            cout << sm + ex << '\n';
        } else {
            upd(l, x);
            if (r != n-1) upd(r+1, -x);
        }
    }
}