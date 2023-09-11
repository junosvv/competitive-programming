#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, x, y;
    cin >> n >> x >> y;
    vi p(n-1), t(n-1);
    FOR(i, 0, n-1) cin >> p[i] >> t[i];
    
    vi res(840);
    FOR(k, 0, 840) {
        res[k] = k + x;
        FOR(i, 0, n-1) {
            res[k] = (res[k] + p[i] - 1) / p[i] * p[i];
            res[k] += t[i];
        }
        res[k] += y;
    }

    int q;
    cin >> q;
    FOR(qi, 0, q) {
        int k;
        cin >> k;
        cout << k/840*840 + res[k%840] << '\n';
    }
}