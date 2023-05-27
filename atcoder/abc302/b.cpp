#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++(i))
#define vi vector<int>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int R, C;
    cin >> R >> C;

    vs grid(R);
    FOR(r, 0, R) cin >> grid[r];
    const string s = "snuke";

    FOR(r, 0, R) FOR(c, 0, C) FOR(dr, -1, 2) FOR(dc, -1, 2) {
        int rr = r, cc = c;
        vector<pii> res;
        FOR(i, 0, 6) {
            if (i == 5) {
                for (pii pr : res) cout << pr.first+1 << ' ' << pr.second+1 << '\n';
                exit(0);
            }
            if (rr < 0 || rr >= R || cc < 0 || cc >= C || grid[rr][cc] != s[i]) break;
            res.emplace_back(rr, cc);
            rr += dr; cc += dc;
        }
    }
}