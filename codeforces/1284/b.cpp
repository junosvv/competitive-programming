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
const int MOD = 1000000007;

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
    
    int n;
    cin >> n;
    vector<vi> seqs(n);
    vi decs;
    vb isdec(n, true);
    REP(i, 0, n) {
        int sz;
        cin >> sz;
        seqs[i].resize(sz);
        cin >> seqs[i];
        REP(j, 1, sz) if (seqs[i][j-1] < seqs[i][j]) isdec[i] = false;
        if (isdec[i]) decs.push_back(seqs[i][0]);
    }
    sort(decs.begin(), decs.end());

    int res=0;
    REP(i, 0, n) if (isdec[i]) {
        int k=-1;
        int upp=decs.size();
        for (int b=upp; b>=1; b/=2) {
            while (k+b<upp && decs[k+b] <= seqs[i].back()) k += b;
        }
        res += k+1;
    }
    cout << n*n-res;
}