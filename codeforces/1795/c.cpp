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

        vector<pii> x(n);

        FOR(i, 0, n) {
            x[i].first = lower_bound(bpref.begin(), bpref.end(), a[i] + bpref[i-1]) - bpref.begin() - i;
            x[i].second = bpref
        }
    }
}