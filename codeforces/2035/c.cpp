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

    auto f = [&](int n) {
        if (n == 1) return 5LL;
        return 2*n-1;
    };

    auto solve = [&]() {
        int n;
        cin >> n;

        if (n == 5) {
            cout << "5\n2 1 3 4 5\n";
            return;
        }
        
        vi res, mark(n+1);
        int min_d = -1;
        FOR(d, 0, 20) {
            int x = 1<<d;
            if (x > n && min_d == -1) min_d = x;
            if (n&x || (!(n&1) && x <= n)) {
                res.push_back(x);
                res.push_back(f(x));
                mark[x] = 1;
                if (f(x) <= n) mark[f(x)] = 1;
            }
        }
        if (res.back() <= n) mark[res.back()] = 0;
        res.pop_back();
        if (n&1) {
            res.push_back(n);
            mark[n] = 1;
        }

        vi res2;
        FOR(i, 1, n+1) if (!mark[i]) res2.push_back(i);
        for (int i : res) res2.push_back(i);
        cout << (n&1 ? n : min_d-1) << '\n';
        for (int i : res2) cout << i << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}