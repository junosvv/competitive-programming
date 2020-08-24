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

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    sort(a.begin(), a.end());
    vi suff(n+1);
    RREP(i, n-1, -1) suff[i] = suff[i+1] + a[i];
    int SFN = 1e5+10;
    vi xx(SFN);
    REP(i, 0, n) ++xx[a[i]];
    RREP(i, SFN-2, -1) xx[i] += xx[i+1];

    int k=0;
    int upp = 1e15+5;
    for (int b=upp; b>=1; b/=2) {
        while (k+b<=upp) {
            int check = k+b;
            int shakes = 0;
            REP(i, 0, n) {
                if (check-a[i] < 0) shakes += n;
                else if (check-a[i] < SFN) shakes += xx[check-a[i]];
            }
            if (shakes < m) break;
            k += b;
        }
    }
    int res = 0, shakes=0;
    REP(i, 0, n) {
        if (k-a[i] < 0) {
            shakes += n;
            res += n*a[i]+suff[0];
        } else if (k-a[i] < SFN) {
            shakes += xx[k-a[i]];
            res += xx[k-a[i]]*a[i] + suff[n-xx[k-a[i]]];
        }
    }
    res -= (shakes-m)*k;
    cout << res;
}