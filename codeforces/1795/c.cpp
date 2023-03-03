#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];

        vi bpref = b;
        FOR(i, 1, n) bpref[i] += bpref[i-1];

        vi resfree(n), res(n);
        FOR(i, 0, n) {
            int prev = i == 0 ? 0 : bpref[i-1];
            int x = upper_bound(bpref.begin(), bpref.end(), prev+a[i]) - bpref.begin();
            ++resfree[i];
            if (x < n) {
                --resfree[x];
                res[x] += prev+a[i] - (x==0 ? 0 : bpref[x-1]);
            }
        }
        FOR(i, 1, n) resfree[i] += resfree[i-1];
        FOR(i, 0, n) res[i] += b[i] * resfree[i];

        FOR(i, 0, n) cout << res[i] << ' ';
        cout << '\n';
    }
}