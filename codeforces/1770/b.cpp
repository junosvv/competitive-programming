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
        int n, k;
        cin >> n >> k;

        vi a(n);
        int l = 1, r = n;
        FOR(i, 0, n) {
            if ((i+1)%k == 0) a[i] = l++;
            else a[i] = r--;
        }

        FOR(i, 0, n) cout << a[i] << ' ';
        cout << '\n';
    }
}