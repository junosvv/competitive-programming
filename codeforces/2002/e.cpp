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

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n), b(n);
        vvi loc(n+1);
        FOR(i, 0, n) {
            cin >> a[i] >> b[i];
            loc[b[i]].push_back(i);
        }
        vi res(n);

        vector<pii> stack;
        FOR(i, 0, n) {
            pii v = {a[i], b[i]};
            int mx = 0;
            if for (int i=stack.size()-1)
            while (!stack.empty() && stack.back().second != v.second && stack.back().first <= v.first) {
                mx = max(mx, stack.back().first);
                stack.pop_back();
            }
            if (!stack.empty() && stack.back().second == v.second) {
                stack.back().first += v.first - mx;
            } else {
                stack.emplace_back(v.first-mx, v.second);
            }
            for (pii pr : stack) cout << pr.first << "," << pr.second << ' ';
            cout << '\n';
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}