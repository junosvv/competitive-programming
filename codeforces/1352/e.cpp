#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
 
        vi poss(n+1);
        FOR(i, 0, n-1) {
            int sm = a[i];
            FOR(j, i+1, n) {
                sm += a[j];
                if (sm > n) break;
                poss[sm] = true;
            }
        }
 
        int res = 0;
        FOR(i, 0, n) if (poss[a[i]]) ++res;
        cout << res << '\n';
    }
}