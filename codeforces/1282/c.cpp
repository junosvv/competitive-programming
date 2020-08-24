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
    
    CASET {
        int n,t;
        vi diff(2);
        cin >> n >> t >> diff;
        vector<pii> probs(n);
        REP(i, 0, n) cin >> probs[i].second;
        REP(i, 0, n) cin >> probs[i].first;
        int total=0;
        REP(i, 0, n) total += diff[probs[i].second];
        if (total <= t) {
            cout << n << '\n';
            continue;
        }
        sort(probs.begin(), probs.end());
        vi easies(n+1);
        RREP(i, n-1, -1) easies[i] = easies[i+1] + !probs[i].second;

        int res = 0;
        int mandtime = 0;
        REP(i, 0, n) {
            if (i!=0) mandtime += diff[probs[i-1].second];
            int s = probs[i].first-1 - mandtime;
            int cur=0;
            if (s>=0) {
                cur += i;
                int temp = min(easies[i], s/diff[0]);
                cur += temp;
                s -= temp*diff[0];
                if (s>=0) {
                    cur += s/diff[1];
                }
            }
            res = max(res, cur);
        }
        cout << res << '\n';
    }
}