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

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi a(2*n); cin >> a;
        vi occ(3);
        REP(i, 0, 2*n) ++occ[a[i]];
        int bal = occ[1]-occ[2];
        if (bal==0) {
            cout << "0\n";
            continue;
        }
        if (bal<0) {
            bal = -bal;
            swap(occ[1], occ[2]);
            REP(i, 0, 2*n) a[i] = 3-a[i];
        }

        int cur=0;
        vi lloc(2*n+2,-1), rloc(2*n+2,-1);
        lloc[0] = n;
        rloc[0] = n-1;
        REP(i, n, 2*n) {
            if (a[i]==1) ++cur;
            else --cur;
            if (cur>0 && rloc[cur]==-1) rloc[cur] = i;
        }
        cur=0;
        RREP(i, n-1, -1) {
            if (a[i]==1) ++cur;
            else --cur;
            if (cur>0 && lloc[cur]==-1) lloc[cur] = i;
        }
        int res = INF;
        REP(i, 0, bal+1) {
            if (lloc[i] == -1 || rloc[bal-i] == -1) continue;
            res = min(res, rloc[bal-i]-lloc[i]+1);
        }
        cout << res << '\n';
    }
}