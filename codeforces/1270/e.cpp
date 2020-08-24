#include <bits/stdc++.h>
using namespace std;

#define int long long
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define sq(x) (x)*(x)
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define t4i tuple<int,int,int,int>
#define mii map<int,int>

const int INF = 1LL<<60;
const int MOD = 998244353;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
string to_string(string s) {return s;}
string to_string(bool b) {return b?"true":"false";}
template <typename A, typename B>
string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) { return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";}
template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}
string bin_string(int x) {
    const int d = 32;
    string result(d, ' ');
    REP(i, 0, d) result[d-1-i] = '0'+(x>>i & 1LL);
    return result;
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

void print(vi res) {
    cout << res.size() << '\n';
    for (int k : res) cout << k << ' ';
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vi x(n), y(n);
    REP(i, 0, n) cin >> x[i] >> y[i];
    if (n==2) {
        print({1});
        return 0;
    }
    vector<vector<vi>> pts;
    while (true) {
        pts.assign(2, vector<vi>(2));
        bool bad = true;
        REP(i, 0, n) {
            pts[x[i]&1][y[i]&1].push_back(i+1);
            if (abs(x[i]) >= 2 || abs(y[i]) >= 2) bad = false;
        }
        int cnt=0;
        REP(i, 0, 2) REP(j, 0, 2) if (!pts[i][j].empty()) ++cnt;
        if (cnt >= 2) break;
        if (bad) {
            vi res;
            REP(i, 0, n) if (x[i]==y[i]) res.push_back(i+1);
            print(res);
            return 0;
        }
        REP(i, 0, n) x[i] >>= 1, y[i] >>= 1;
    }
    
    vb seen(2);
    REP(i, 0, 2) REP(j, 0, 2) if (!pts[i][j].empty()) seen[i+j&1] = true;
    if (!seen[0] || !seen[1]) {
        REP(i, 0, 2) REP(j, 0, 2) if (!pts[i][j].empty()) {
            print(pts[i][j]);
            return 0;
        }
    } else {
        vi res;
        REP(i, 0, 2) REP(j, 0, 2) if (i+j&1) {
            for (int k : pts[i][j]) res.push_back(k);
        }
        print(res);
    }
}