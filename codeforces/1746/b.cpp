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
 
        int i=0, j=n-1;
        int res = 0;
        while (i < j) {
            if (a[i] == 0) ++i;
            else if (a[j]) --j;
            else {
                ++res;
                ++i;
                --j;
            }
        }
        cout << res << '\n';
    }
}