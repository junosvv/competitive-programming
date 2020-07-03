#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define tiiii tuple<int,int,int,int>
#define mii map<int,int>
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 998244353;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
string to_string(string s) {return s;}
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
    RREP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
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
    vi x(n);
    cin >> x;
    sort(x.begin(), x.end());

    vector<pii> comps(1); comps[0] = {-INF, -1};
    REP(i, 0, n) {
        comps.back().second = x[i]-1;
        comps.push_back({x[i]+1, -1});
    }
    vector<pii> comps2;
    REP(i, 0, comps.size()) if (comps[i].first<=comps[i].second) comps2.push_back(comps[i]);
    comps = comps2;
    comps.push_back({x.back()+1, INF});

    vi res;
    int resval=0;
    int k=1;
    while (m) {
        int i=0;
        vb delet(comps.size());
        REP(i, 0, comps.size()) {
            if (comps[i].first != -INF) {
                res.push_back(comps[i].first);
                resval += k;
                ++comps[i].first;
                if (comps[i].first > comps[i].second) delet[i] = true;
                --m;
                if (!m) break;
            }
            if (comps[i].second != INF && !delet[i]) {
                res.push_back(comps[i].second);
                resval += k;
                --comps[i].second;
                if (comps[i].first > comps[i].second) delet[i] = true;
                --m;
                if (!m) break;
            }
        }
        vector<pii> newcomps;
        REP(i, 0, comps.size()) if (!delet[i]) newcomps.push_back(comps[i]);
        comps = newcomps;
        ++k;
    }
    cout << resval << '\n';
    REP(i, 0, res.size()) cout << res[i] << ' ';
}