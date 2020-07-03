#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (__typeof(l) i = (l); i != (r); (l)<(r)?++i:--i)
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 1000000007;

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}

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

template <typename A>
string to_string(A x[], signed n) {
    string result = "{";
    for (signed i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    for (signed i=d-1; i>=0; --i) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

int powa(int base, int exp) {
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp>>1);
    val = val*val % MOD;
    if (exp&1) {
        val = val*base % MOD;
    }
    return val;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int a[3] = {};
    int res = 1;
    REP(i, 0, n) {
        int x;
        cin >> x;
        int poss = 0;
        REP(j, 0, 3) if (a[j] == x) ++poss;
        res *= poss;
        res %= MOD;
        REP(j, 0, 3) {
            if (a[j] == x) {
                ++a[j];
                break;
            }
        }
    }
    cout << res;
}