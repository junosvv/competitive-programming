#include <bits/stdc++.h>
using namespace std;

#define int long long
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define print(x) cout << to_string(x)
#define println(x) cout << to_string(x) << '\n'
#define m2d(typ, v, a, b, x) vector<vector<typ>> v(a, vector<tp>(b, x))
#define m3d(typ, v, a, b, c, x) vector<vector<vector<typ>>> v(a, vector<vector<typ>>(b, vector<typ>(c, x)))
#define m4d(typ, v, a, b, c, d, x) vector<vector<vector<vector<typ>>>> v(a, vector<vector<vector<typ>>>(b, vector<vector<typ>>(c, vector<typ>(d, x))))
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)

int INF = 1LL<<60;
int MOD = 998244353;

template <typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
string to_string(string &s) {return s;}
string to_string(const char s[]) {return (string)s;}
template <typename A, typename B>
string to_string(pair<A, B> p);
template <class C>
string to_string(C &v) {
    string res = "[";
    bool first = true;
    for (auto i : v) {
        if (!first) res += ", ";
        res += to_string(i);
        first = false;
    }
    res += ']';
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <class C>
void write(C &v, string sep=" ", string end="\n") {
    for (auto i : v) cout << to_string(i) << sep;
    cout << end;
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
    
    int n;
    cin >> n;
    cout << "? " << 1 << ' ' << n << endl;
    multiset<pair<int, string>> inp;
    REP(i, 0, n*(n+1)/2) {
        string x;
        cin >> x;
        sort(x.begin(), x.end());
        inp.insert({x.size(), x});
    }
    if (n!=1) {
        cout << "? " << 2 << ' ' << n << endl;
        REP(i, 0, n*(n-1)/2) {
            string x;
            cin >> x;
            sort(x.begin(), x.end());
            auto it = inp.find({x.size(), x});
            if (it != inp.end()) inp.erase(it);
        }
    }
    vi prev(26);
    string res;
    for (auto pr : inp) {
        vi cur(26);
        REP(i, 0, pr.first) ++cur[pr.second[i]-'a'];
        REP(i, 0, 26) if (prev[i] != cur[i]) {
            res += 'a'+i;
            break;
        }
        prev = cur;
    }
    cout << "! " << res;
}