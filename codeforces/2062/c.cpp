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
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        
        int res = accumulate(a.begin(), a.end(), 0LL);
        while (n > 1) {
            vi b(n-1);
            FOR(i, 0, n-1) b[i] = a[i+1] - a[i];
            a = b;
            --n;
            int cur = 0;
            FOR(i, 0, n) cur += a[i];
            res = max(res, abs(cur));
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}