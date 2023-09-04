#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        
        auto f = [&](int upp) {
            int res = 0;
            int k = 1;
            vi stack;
            int mx = 0;
            ROF(i, n, 0) {
                while (k <= n && k <= upp/i) stack.push_back(k++);
                if (stack.empty()) return 0LL;
                int cur = i * stack.back();
                stack.pop_back();
                res += cur;
                mx = max(mx, cur);
            }
            return res - mx;
        };

        int res = 0;
        FOR(x, 1, n+1) FOR(y, x, n+1) {
            res = max(res, f(x*y));
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}   