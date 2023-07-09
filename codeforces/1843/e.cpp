#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n, m;
        cin >> n >> m;
        vi l(m), r(m);
        FOR(i, 0, m) {
            cin >> l[i] >> r[i];
            --l[i]; --r[i];
        }
        int q;
        cin >> q;
        vi a(q);
        FOR(i, 0, q) {
            cin >> a[i];
            --a[i];
        }
        
        auto check = [&](int k) {
            vi pref(n);
            FOR(i, 0, k+1) pref[a[i]] = 1;
            FOR(i, 1, n) pref[i] += pref[i-1];
            FOR(i, 0, m) {
                if (pref[r[i]] - (l[i] == 0 ? 0 : pref[l[i]-1]) >= (r[i]-l[i]+3)/2) return true;
            }
            return false;
        };

        int k=q;
        for (int b=q; b>=1; b/=2) {
            while (k-b >= 0 && check(k-b)) k -= b;
        }
        cout << (k==q ? -1 : k+1) << '\n';
    }
}