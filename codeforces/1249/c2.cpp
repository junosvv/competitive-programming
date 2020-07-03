#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
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
string to_string(A x[], int n) {
    string result = "{";
    REP(i, 0, n) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    REP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    const int d = 39;

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int x[d];
        int tk = 1;
        RREP(i, d-1, -1) {
            x[i] = n%(tk*3)/tk;
            tk *= 3;
        }
        int left = -1;
        REP(i, 0, d) {
            if (x[i] == 2) {
                left = i;
                break;
            }
        }
        if (left == -1) cout << n << '\n';
        else {
            REP(i, left, d) x[i] = 0;
            RREP(i, left-1, -1) {
                if (x[i] == 0) {
                    x[i] = 1;
                    break;
                }
                x[i] = 0;
            }
            int res = 0;
            tk = 1;
            REP(i, 0, 39) {
                res += tk*x[d-i-1];
                tk *= 3;
            }
            cout << res << '\n';
        }
    }
}