#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    FOR(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    int res = 0;
    int sum = 0;
    FOR(i, 0, n) {
        if (sum + a[i] > k) break;
        sum += a[i];
        ++res;
    }
    cout << res;
}
