#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;

    int res = 1;
    FOR(i, 0, n) {
        int m, k;
        cin >> m >> k;
        k = min(k, m-k);

        if (k) {
            res *= m;
            if (res > 1e9) res = 0;
        }
        FOR(j, 2, k+1) {
            res *= m-j+1;
            res /= j;
            if (res > 1e9) res = 0;
        }
    }

    if (res == 0) cout << "BIG ENOUGH";
    else cout << res;
}