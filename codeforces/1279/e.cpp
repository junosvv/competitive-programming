#include <bits/stdc++.h>
using namespace std;

#define int long long
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define print(x) cout << to_string(x) << ' '
#define println(x) cout << to_string(x) << '\n'
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)

int INF = 1LL<<60;
int MOD = 998244353;

string to_string(string &s) {return s;}
string to_string(const char s[]) {return (string)s;}
template <class C> string to_string(C &v) {
    string res;
    for (auto &i : v) res += to_string(i) + ' ';
    return res; 
}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {for (auto &x : v) is >> x; return is;}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> &v);
template <typename A> ostream &operator<<(ostream &os, vector<A> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A> ostream &operator<<(ostream &os, set<A> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A> ostream &operator<<(ostream &os, multiset<A> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A, typename B> ostream &operator<<(ostream &os, map<A,B> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> &pr) {os << '(' << pr.first << ", " << pr.second << ')';}
string bin_string(int x) {
    const int d = 32;
    string res(d, ' ');
    REP(i, 0, d) res[d-1-i] = '0'+(x>>i & 1LL);
    return res;
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

vi fact(21, 1);
int facto(int x) {
    if (x<0) return 1;
    return fact[x];
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    REP(i, 1, fact.size()) fact[i] = i*fact[i-1];
    vi goods(23); goods[0] = 1;
    REP(k, 1, goods.size()) REP(i, 1, k+1) goods[k] += goods[k-i] * facto(i-2);
    
    CASET {
        int n, rnk;
        cin >> n >> rnk;
        int n0=n;
        n = min(22LL, n);
        if (rnk > goods[n]) {
            println(-1);
            continue;
        }

        int cur = 1;
        int k = 0;
        vi comps(1, 1);
        vi compticks;
        RREP(right, n-1, 0) {
            if (cur+goods[right]*facto(comps[k]-2) <= rnk) {
                cur += goods[right]*facto(comps[k]-2);
                ++comps[k];
            } else {
                comps.push_back(1);
                compticks.push_back((rnk-cur)/goods[right]);
                cur += compticks.back()*goods[right];
                ++k;
            }
        }
        compticks.push_back(rnk-cur);

        vector<vi> answers(comps.size());
        REP(i, 0, comps.size()) {
            answers[i] = {0, comps[i], 0};
            int k = 2;
            vb seen(comps[i]+1); seen[comps[i]] = true;
            vi ult(comps[i]+1), invult(comps[i]+1);
            REP(j, 1, comps[i]+1) ult[j] = invult[j] = j;
            ult[1] = comps[i];
            invult[comps[i]] = 1;
            int c=0;
            // cout << "cur comp: " << comps[i] << " compticks[i]: " << compticks[i] << endl;
            while (k<=comps[i]) {
                // cout << "pos " << k << " trying " << answers[i][k] << endl;
                if (!answers[i][k] || c+facto(comps[i]-1-k) <= compticks[i]) {
                    // cout << "skipping " << answers[i][k] << endl;
                    if (answers[i][k]) c += facto(comps[i]-1-k);
                    while (true) {
                        ++answers[i][k];
                        if (!seen[answers[i][k]] && (k==comps[i] || ult[answers[i][k]] != k)) break;
                    }
                } else {
                    // cout << "settled on " << answers[i][k] << endl;
                    seen[answers[i][k]] = true;
                    ult[invult[k]] = ult[answers[i][k]];
                    invult[ult[answers[i][k]]] = invult[k];
                    answers[i].push_back(0);
                    ++k;
                }
            }
        }
        int sm = n0-n;
        REP(i, 1, sm+1) print(i);
        for (vi &v : answers) {
            for (int i : v) if (i) print(i+sm);
            sm += v.size()-2;
        }
        cout << '\n';
    }
}