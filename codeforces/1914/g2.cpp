#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(2*n);
        FOR(i, 0, 2*n) {
            cin >> a[i];
            --a[i];
        }

        vi cnt(n), stack;
        vvi G(n), GT(n);
        FOR(i, 0, 2*n) {
            while (!stack.empty() && cnt[stack.back()] == 2) stack.pop_back();
            if (!stack.empty()) {
                int x = stack.back();
                stack.pop_back();
                while (!stack.empty() && cnt[stack.back()] == 2) stack.pop_back();
                stack.push_back(x);
            }

            stack.push_back(a[i]);
            int k = stack.size();
            if (k >= 2) {
                G[stack[k-2]].push_back(stack[k-1]);
                GT[stack[k-1]].push_back(stack[k-2]);
                // cout << "connect " << stack[k-2]+1 << ' ' << stack[k-1]+1 << '\n';
            }

            ++cnt[a[i]];
        }

        vi tour, seen(n);
        function<void(int)> dfs = [&](int u) {
            seen[u] = true;
            for (int v : G[u]) if (!seen[v]) {
                dfs(v);
            }
            tour.push_back(u);
        };
        FOR(u, 0, n) if (!seen[u]) dfs(u);
        reverse(tour.begin(), tour.end());

        int c = 0;
        vi comp(n, -1);
        dfs = [&](int u) {
            // cout << "set " << u << " to " << c << '\n';
            comp[u] = c;
            for (int v : GT[u]) if (comp[v] == -1) {
                dfs(v);
            }
        };

        for (int u : tour) if (comp[u] == -1) {
            dfs(u);
            ++c;
        }

        vi incl(c, 1), compsize(c);
        FOR(u, 0, n) {
            ++compsize[comp[u]];
            for (int v : G[u]) if (comp[u] != comp[v]) incl[comp[v]] = 0;
        }

        int res = 1;
        FOR(i, 0, c) if (incl[i]) res = res * 2 * compsize[i] % MOD;
        cout << accumulate(incl.begin(), incl.end(), 0) << ' ' << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}