#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, V;
    cin >> n >> V;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vi comps = {1};
    FOR(i, 1, n) {
        if (a[i] - a[i-1] > V) {
            comps.push_back(0);
        }
        ++comps.back();
    }
    if (comps.size() >= 20) {
        FOR(i, 0, n) cout << "Impossible\n";
        exit(0);
    }

    vi scale = {V};
    while (scale.back() > 0) {
        scale.push_back(scale.back() / 2);
    }
    reverse(scale.begin(), scale.end());
    int m = scale.size() - 1;

    vvi nxt(m+1, vi(n+1));
    FOR(j, 0, m+1) {
        nxt[j][n-1] = n-1;
        nxt[j][n] = n;
        ROF(i, n-2, -1) {
            if (a[i+1] - a[i] > scale[j]) {
                nxt[j][i] = i;
            } else {
                nxt[j][i] = nxt[j][i+1];
            }
        }
    }
    
    auto solve = [&](int l, int r) {
        int n = r - l;

        vi dp(1<<m, l-1);
        FOR(mask, 1, 1<<m) {
            FOR(d, 0, m) if (mask>>d&1) {
                dp[mask] = max(dp[mask], nxt[d][dp[mask^(1<<d)] + 1]);
            }
            dp[mask] = min(dp[mask], r-1);
        }

        return dp;
    };

    FOR(i, 0, n) if (i == 0 || a[i] - a[i-1] > V) {
        vi dpb = solve(0, i), dpc = solve(nxt[m][i]+1, n);

        bool poss = false;
        FOR(maskb, 0, 1<<m) {
            int maskc = (1<<m)-1 - maskb;
            if (dpb[maskb] == i-1 && dpc[maskc] == n-1) {
                poss = true;
                break;
            }
        }
        FOR(j, i+1, n+1) {
            cout << (poss ? "Possible" : "Impossible") << '\n';
            if (j == n || a[j] - a[j-1] > V) break;
        }   
    }
}