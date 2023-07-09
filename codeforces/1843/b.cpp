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
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        
        int res = 0;
        int ops = 0;
        int flag = 1;
        FOR(i, 0, n) {
            if (a[i] < 0) {
                ops += flag;
                flag = 0;
            } else if (a[i] > 0) {
                flag = 1;
            }
            res += abs(a[i]);
        }
        cout << res << ' ' << ops << '\n';
    }
}