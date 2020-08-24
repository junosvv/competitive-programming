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
 
main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int R,C;
    cin >> R >> C;
    vector<vb> grid(R, vb(C));
    REP(r, 0, R) REP(c, 0, C) {
        char x;
        cin >> x;
        grid[r][c] = (x=='.');
    }
    vector<vi> hpref(R, vi(C+1)), vpref(R+1, vi(C));
    REP(r, 0, R) RREP(c, C-1, -1) hpref[r][c] = hpref[r][c+1] + grid[r][c];
    REP(c, 0, C) RREP(r, R-1, -1) vpref[r][c] = vpref[r+1][c] + grid[r][c];
    if (R==1 && C==1) {
        cout << 1;
        return 0;
    }
    vector<vector<pii>> dp(R, vector<pii>(C));
    dp[R-1][C-1] = {0, 1};
    RREP(r, R-1, -1) RREP(c, C-1, -1) {
        if (r==R-1 && c==C-1) continue;
        if (r==R-1) dp[r][c].first = 0;
        else if (vpref[r+1][c] != 0) {
            if (grid[r+1][c]) dp[r][c].first = dp[r+1][c].second + dp[r+1][c].first;
            else dp[r][c].first = MOD + dp[r+1][c].second + dp[r+1][c].first - dp[r+vpref[r+1][c]+1][c].second;
        }
        if (c==C-1) dp[r][c].second = 0;
        else if (hpref[r][c+1] != 0) {
            if (grid[r][c+1]) dp[r][c].second = dp[r][c+1].first + dp[r][c+1].second;
            else {
                if (r==R-1 && c+hpref[r][c+1]+1==C-1) dp[r][c].second = MOD + dp[r][c+1].first + dp[r][c+1].second - 1;
                else dp[r][c].second = MOD + dp[r][c+1].first + dp[r][c+1].second - dp[r][c+hpref[r][c+1]+1].first;
            }
        }
        dp[r][c].first %= MOD;
        dp[r][c].second %= MOD;
    }
    cout << (dp[0][0].first + dp[0][0].second) % MOD;
}