#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    vi r1(k), c1(k), r2(k), c2(k);
    FOR(i, 0, k) {
        cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
        --r1[i]; --c1[i]; --r2[i]; --c2[i];
    }

    auto pw = [&](int x) {
        return (x&1LL) ? -1 : 1;
    };

    int res = n*n;
    FOR(d, 1, n) if (n%d==0) {
        int whiteTL = (n/d)*(n/d) / 2 * d*d;
        int blackTL = ((n/d)*(n/d) + 1) / 2 * d*d;
        int cur = 0;

        FOR(i, 0, k) {
            int br = r1[i] / d;
            int pr = r1[i] % d;
            int bc = c1[i] / d;
            int pc = c1[i] % d;
            int dr = r2[i] / d;
            int qr = r2[i] % d;
            int dc = c2[i] / d;
            int qc = c2[i] % d;

            int xr = pw(br)*(d-pr) + pw(dr)*(qr+1);
            int xc = pw(bc)*(d-pc) + pw(dc)*(qc+1);

            int corners = xr*xc;
            int verti = ((br+dr)&1LL) ? 0 : pw(br+1)*d*xc;
            int horiz = ((bc+dc)&1LL) ? 0 : pw(bc+1)*d*xr;
            int centr = ((br+dr)&1LL || (bc+dc)&1LL) ? 0 : d*d*pw(br+bc);

            int thisRect = corners + verti + horiz + centr;
            cur += thisRect;
        }
        res = min(res, whiteTL + cur);
        res = min(res, blackTL - cur);
    }
    cout << res << '\n';
}