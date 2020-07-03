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

string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    RREP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

vi getZ(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    REP(i, 1, n) {
        z[i] = max(0LL, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i;
            y = i+z[i];
            ++z[i];
        }
    }
    return z;
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
    string s;
    cin >> n >> s;
    vi occ(2);
    REP(i, 0, n) {
        if (s[i]=='B') ++occ[1];
        else ++occ[0];
    }  
    if (occ[0]&1 && occ[1]&1) cout << -1;
    else {
        if (occ[1]&1) {
            swap(occ[0], occ[1]);
            REP(i, 0, n) {
                if (s[i] == 'B') s[i] = 'W';
                else s[i] = 'B';
            }
        }
        vi res;
        REP(l, 0, n-1) {
            if (s[l] == 'B' && s[l+1] == 'B' || s[l] == 'B' && s[l+1] == 'W') {
                res.push_back(l);
                if (s[l] == 'B') s[l] = 'W';
                else s[l] = 'B';
                if (s[l+1] == 'W') s[l+1] = 'B';
                else s[l+1] = 'W';
            }
        }
        cout << res.size() << '\n';
        for (int i : res) cout << i+1 << ' ';
    }
}