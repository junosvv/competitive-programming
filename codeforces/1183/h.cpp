#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, l, r) for (int i=(l); i<(r); ++i)
#define RFOR(i, r, l) for (int i=(r); i>(l); --i)
#define vi vector<int>
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 1000000007;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> istream &operator>>(istream &is, T arr[]){ for (auto &x : arr) is >> x; return is; }

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
    FOR(i, 0, n) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    RFOR(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

vector<int> getZ(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    FOR(i, 1, n) {
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

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vi> last(26, vi(n, -1));
    FOR(pos, 0, n) {
        FOR(i, pos, n) last[s[pos]-'a'][i] = pos;
    }

    vector<vi> dp(n+1, vi(n+1));
    FOR(i, 0, n) dp[1][i] = 1;
    FOR(len, 2, n+1) {
        FOR(ind, 1, n+1) {
            FOR(c, 0, 26) {
                if (last[c][ind-1] != -1) {
                    dp[len][ind] += dp[len-1][last[c][ind-1]];
                }
            }
        }
        dp[len-1][n] = dp[len][n];
    }
    dp[n][n] = 1;
    int cnt=0, cost=0;
    RFOR(len, n, 0) {
        if (cnt >= k) break;
        if (cnt+dp[len][n] >= k) {
            cost += (k-cnt)*(n-len);
            cnt = k;
            break;
        }
        cost += dp[len][n]*(n-len);
        cnt += dp[len][n];
    }
    if (cnt >= k) cout << cost;
    else if (cnt == k-1) cout << cost+n;
    else cout << -1;
}