#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, H;
    cin >> n >> H;

    bool fail = false;
    int res = 0;
    FOR(i, 0, n) {
        vi a(3);
        FOR(j, 0, 3) cin >> a[j];
        sort(a.begin(), a.end());
        if (H < a[0]) fail = true;
        else if (H < a[1]) res += a[1];
        else res += a[0];
    }
    if (fail) cout << "impossible\n";
    else cout << res << '\n';
}