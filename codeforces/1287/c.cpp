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
    
    int n;
    cin >> n;
    vi a(n);
    vi z(2);
    z[0] = n/2;
    z[1] = n-z[0];
    bool stop = true;
    REP(i, 0, n) {
        int x;
        cin >> x;
        if (x==0) a[i] = -1;
        else {
            stop = false;
            a[i] = x&1;
            --z[a[i]];
        }
    }
    if (stop) {
        cout << (n!=1);
        return 0;
    }
 
    vector<vector<pii>> segs(2);
    int i=0, j=0;
    while (true) {
        while (i<n-1 && (a[i] == -1 || a[i+1] != -1)) ++i;
        j=i+1;
        while (j<n && a[j] == -1) ++j;
        if (j==n) break;
        if (a[i]==a[j]) segs[a[i]].push_back({j-i-1, i+1});
        i=j;
    }
    
    REP(i, 0, 2) {
        sort(segs[i].begin(), segs[i].end());
        REP(ind, 0, segs[i].size()) {
            int len, u; tie(len, u) = segs[i][ind];
            if (z[i] >= len) {
                REP(j, u, u+len) a[j] = i;
                z[i] -= len;
            } else REP(j, u, u+len) a[j] = 1-i;
        }
        REP(j, 0, n) if (a[j] != -1) {
            if (a[j] == i) {
                if (z[i] >= j) {
                    REP(k, 0, j) a[k] = i;
                    z[i] -= j;
                }
                else REP(k, 0, j) a[k] = 1-i;
            }
            break;
        }
        REP(j, 0, n) if (a[n-1-j] != -1) {
            if (a[n-1-j] == i) {
                if (z[i] >= j) {
                    REP(k, n-j, n) a[k] = i;
                    z[i] -= j;
                }
                else REP(k, n-j, n) a[k] = 1-i;
            }
            break;
        }
    }
    REP(i, 0, n) if (a[i]==-1) a[i] = 1;
 
    int res = 0;
    REP(i, 1, n) {
        if (a[i-1] != a[i]) ++res;
    }
    cout << res;
}