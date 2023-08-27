#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int R, C;
    cin >> R >> C;
    vvi capac(2*R+2, vi(2*R+2));
    FOR(r, 0, R) FOR(c, 0, C) {
        int x;
        cin >> x;
        --x;
        ++capac[r][R+x];
    }
    FOR(r, 0, R) {
        ++capac[2*R][r];
        ++capac[R+r][2*R+1];
    }
    vvi resid = capac;

    vi seen(2*R+2);
    function<bool(int)> dfs = [&](int u) {
        FOR(v, 0, 2*R+2) if (resid[u][v]) if (!seen[v]) {
            seen[v] = true;
            if (v == 2*R+1 || dfs(v)) {
                --resid[u][v];
                ++resid[v][u];
                return true;
            }
        }
        return false;
    };

    vvi res(R, vi(C));
    FOR(c, 0, C) {
        FOR(r, 0, R) {
            seen.assign(2*R+2, false);
            dfs(2*R);
        }
        FOR(r, 0, R) FOR(rr, 0, R) {
            if (resid[r][R+rr] < capac[r][R+rr]) {
                res[r][c] = rr+1;
                --capac[r][R+rr];
                resid[R+rr][r] = capac[R+rr][r];                
            }
        }
        FOR(r, 0, R) {
            resid[2*R][r] = capac[2*R][r];
            resid[R+r][2*R+1] = capac[R+r][2*R+1];
        }
    }
    cout << "Yes\n";
    FOR(r, 0, R) {
        FOR(c, 0, C) cout << res[r][c] << ' ';
        cout << '\n';
    }
}