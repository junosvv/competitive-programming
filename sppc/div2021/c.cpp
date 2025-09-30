#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<string> strs(n);
    FOR(i, 0, n) cin >> strs[i];
    int ores = 0;
    int ties = 0;
    FOR(ci, 0, 26) {
        FOR(u, 0, 2) {
            char c;
            if (u) c = 'A'+ci;
            else c = 'a'+ci;

            int res = 0;
            int cur = 0;
            FOR(i, 0, n) {
                bool flag = false;
                FOR(j, 0, k) {
                    if (j >= strs[i].size()) break;
                    if (strs[i][j] == c) {
                        flag = true;
                        break;
                    }
                }
                if (flag) ++cur;
                else {
                    res = max(res, cur);
                    cur = 0;
                }
            }
            
            res = max(res, cur);
            if (res > ores) {
                ores = res;
                ties = 1;
            } else if (res == ores) {
                ++ties;
            }
        }
    }
    cout << ores << ' ' << ties;
}
