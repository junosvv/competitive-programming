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

        bool res = true;
        FOR(i, 0, n) FOR(j, i+1, n) if (a[i] == a[j]) res = false;
        
        int upp = (n>>1) + 1;
        vi sieve(upp);
        FOR(p, 2, upp) if (!sieve[p]) {
            vi b(p);
            FOR(i, 0, n) {
                ++b[a[i]%p];
            }
            if (*min_element(b.begin(), b.end()) >= 2) {
                res = false;
                break;
            }
            for (int u=p*p; u<upp; u+=p) sieve[u] = p;
        }

        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
}