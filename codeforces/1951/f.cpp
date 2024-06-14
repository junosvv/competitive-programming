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
        int n, k;
        cin >> n >> k;
        vi p(n), loc(n);
        FOR(i, 0, n) {
            cin >> p[i];
            --p[i];
            loc[p[i]] = i;
        }
        
        vi tree(n+1);
        auto upd = [&](int x, int val) {
            ++x;
            while (x <= n) {
                tree[x] += val;
                x += x&-x;
            }
        };

        auto prefq = [&](int x) {
            ++x;
            int res = 0;
            while (x) {
                res += tree[x];
                x -= x&-x;
            }
            return res;
        };

        auto query = [&](int l, int r) {
            return prefq(r) - prefq(l-1);
        };

        vi bigg(n);
        ROF(i, n-1, -1) {
            upd(p[i], 1);
            bigg[p[i]] = query(p[i]+1, n-1);
        };

        int corrp = accumulate(bigg.begin(), bigg.end(), 0LL);
        int invp = n*(n-1)/2 - corrp;

        k -= invp;
        if (k < 0 || k&1LL) {
            cout << "NO\n";
            return;
        }
        k /= 2;
        if (k > corrp) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";

        int cnt = 0;
        vi q(n);
        ROF(j, n-1, -1) {
            if (cnt + bigg[j] >= k) {
                int t = 1;
                FOR(i, 0, j) q[i] = t++;

                ROF(i, n-1, j) {
                    q[i] = t++;
                    if (loc[j] < loc[i]) ++cnt;
                    if (cnt >= k) break;
                }
                q[j] = t++;
                ROF(i, n-1, -1) if (!q[i]) q[i] = t++;
                break;
            }
            cnt += bigg[j];
        }
        for (int i : q) cout << i << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}