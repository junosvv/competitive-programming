#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(3);
    FOR(i, 0, 3) cin >> a[i];

    vvi DELTAS = {{0, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}};

    map<vi, int> dp;
    function<int(vi)> solve = [&](vi state) {
        if (state[0] == -1) return (int)(state[1] == 0 && state[2] == 0 && state[3] == 0 && state[7] && state[8] && state[9]);
        if (dp.count(state)) return dp[state];
        // cout << "calcing ";
        // for (int i : state) cout << i << ' ';
        // cout << '\n';
        dp[state] = 0;
        vi state0 = state;
        FOR(d, 0, 4) {
            state = state0;
            bool succ = true;
            FOR(i, 0, 3) {
                if (DELTAS[d][i]) {
                    if (!(n>>state[0]&1LL) && !state[4+i]) {
                        succ = false;
                        break;
                    }
                    state[1+i] = (state[1+i] + (1LL<<state[0])) % a[i];
                    state[7+i] = 1;
                } else {
                    if (n>>state[0]&1LL) state[4+i] = 1;
                }
            }
            --state[0];
            if (succ) dp[state0] = (dp[state0] + solve(state)) % MOD;
        }
        return dp[state0];
    };

    vi state(10);
    state[0] = 62;
    cout << solve(state);
}