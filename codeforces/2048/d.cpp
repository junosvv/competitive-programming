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
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, m) cin >> b[i];
        sort(b.begin(), b.end());

        int me = a[0];
        vi a2;
        FOR(i, 0, n) if (a[i] > me) a2.push_back(a[i]);
        a = a2;
        sort(a.begin(), a.end());
        n = a.size();

        vi cnt(n);
        int magic = -1;
        while (magic+1 < m && me >= b[magic+1]) ++magic;
        int j = magic;
        FOR(i, 0, n) {
            while (j+1 < m && a[i] >= b[j+1]) ++j;
            cnt[i] = j - magic;
        }
        
        vi res(m+1);
        
        // method 1
        FOR(k, 1, m+1) {
            res[k] = m/k;
            FOR(i, 0, n) {
                res[k] += (cnt[i]-(m%k)+k-1)/k;
            }
        }

        FOR(k, 1, m+1) cout << res[k] << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}