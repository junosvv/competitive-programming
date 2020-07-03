#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 998244353;

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

int powa(int base, int exp) {
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp/2);
    val = (val*val)%MOD;
    if (exp%2==1) {
        val *= base;
        val %= MOD;
    }
    return val;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int soldN, n, trapN, t;
    cin >> soldN >> n >> trapN >> t;
    int solds[soldN];
    REP(i, 0, soldN) cin >> solds[i];
    sort(solds,solds+soldN, greater<int>());
    tuple<int,int,int> traps[trapN];
    REP(i, 0, trapN) {
        int a,b,c;
        cin >> a >> b >> c;
        traps[i] = {a,b,c}; // l r d
    }
    sort(traps,traps+trapN);

    int k=0;
    for (int b=soldN; b>=1; b/=2) {
        while (k+b <= soldN) {
            int worst = solds[k+b-1];
            int thist = 0;
            int pos = 0;
            int i=0;
            while (i<trapN) {
                int l, r, d;
                tie(l, r, d) = traps[i];
                if (d <= worst) {
                    ++i;
                } else {
                    thist += l-1-pos;
                    pos = l-1;
                    int upto = r;
                    bool flag = false;
                    REP(j, i+1, trapN) {
                        int l2, r2, d2;
                        tie(l2, r2, d2) = traps[j];
                        if (d2 <= worst) continue;
                        if (l2 <= upto) {
                            upto = max(upto, r2);
                        } else {
                            i = j;
                            flag = true;
                            break;
                        }
                    }
                    thist += 3*(upto-pos);
                    pos = upto;
                    if (!flag) break;
                }
            }
            thist += n+1-pos;
            if (thist > t) break;
            k += b;
        }
    }
    cout << k;
}