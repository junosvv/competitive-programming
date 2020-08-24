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

void upd(vi &tree, int x, int delta) {
    while (x < tree.size()) {
        tree[x] += delta;
        x += x & -x;
    }
}

int pref(vi &tree, int x) {
    int res = 0;
    while (x > 0) {
        res += tree[x];
        x -= x & -x;
    }
    return res;
}

int query(vi &tree, int l, int r) {
    return pref(tree, r) - pref(tree, l-1);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vi a(n+1), loc(n+1), inv(n+1), res(n+1), invtree(n+1), pos(n+1), there(n+1);
    REP(i, 1, n+1) {
        cin >> a[i];
        loc[a[i]] = i;
    }

    upd(invtree, n-loc[1]+1, 1);
    REP(i, 2, n+1) {
        inv[i] = inv[i-1] + pref(invtree, n-loc[i]);
        upd(invtree, n-loc[i]+1, 1);
    }

    REP(i, 1, n+1) {
        upd(there, i, 1);
        upd(pos, i, i);
    }
    RREP(i, n-1, 1) {
        upd(there, loc[i+1], -1);
        upd(pos, loc[i+1], -query(pos, loc[i+1], loc[i+1]));
        int med=0;
        for (int b=n; b>=1; b/=2) {
            while (med+b <= n && pref(there, med+b-1) <= (i-1)/2) med += b;
        }
        
        int left = pref(there, med-1);
        int right = i-left-1;
        res[i] = left*med - pref(pos, med-1) + query(pos, med+1, n) - right*med - left*(left+1)/2 - right*(right+1)/2;
    }
    REP(i, 1, n+1) cout << inv[i]+res[i] << ' ';
}