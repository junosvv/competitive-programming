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

vector<int> getZ(string s) {
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
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp>>1);
    val = val*val % MOD;
    if (exp&1) {
        val = val*base % MOD;
    }
    return val;
}

int n,m,A,B;
vector<vi> nodes;
vb aReach, bReach;

void dfsA(int cur) {
    if (cur==B || aReach[cur]) return;
    aReach[cur] = true;
    for (int nxt : nodes[cur]) {
        dfsA(nxt);
    }
}

void dfsB(int cur) {
    if (cur==A || bReach[cur]) return;
    bReach[cur] = true;
    for (int nxt : nodes[cur]) {
        dfsB(nxt);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {    
        cin >> n >> m >> A >> B;
        nodes.assign(n+1, {});
        REP(i, 0, m) {
            int a,b;
            cin >> a >> b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }

        aReach.assign(n+1, 0);
        bReach.assign(n+1, 0);

        dfsA(A);
        dfsB(B);
        aReach[B] = true;
        bReach[A] = true;
        int aCnt=0, bCnt=0;
        REP(i, 1, n+1) {
            if (!aReach[i]) ++aCnt;
            if (!bReach[i]) ++bCnt;
        }
        cout << aCnt*bCnt << '\n';
    }
}