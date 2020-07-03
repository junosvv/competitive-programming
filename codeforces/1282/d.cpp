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
#define popcount __builtin_popcountll
 
const int INF = 1LL<<60;
const int MOD = 1000000007;
 
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
    for (int i=d-1; i>=0; --i) result[d-1-i] = '0'+((x&1LL<<i)!=0);
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
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "a" << endl;
    int n;
    cin >> n;
    if (n==0) exit(0);
    if (n==300) {
        string fin(n, 'b');
        cout << fin << endl;
        cin >> n;
        exit(0);
    }
    ++n;
    string ans(n, 'a');
    cout << ans << endl;
    int best;
    cin >> best;
    if (best==0) exit(0);
    if (best==n) {
        string fin(n-1, 'b');
        cout << fin << endl;
        cin >> n;
    } else {
        REP(i, 0, n) {
            ans[i] = 'b';
            cout << ans << endl;
            int val;
            cin >> val;
            if (val==0) exit(0);
            if (val >= best) ans[i] = 'a';
            best = min(best, val);
        }
    }
}