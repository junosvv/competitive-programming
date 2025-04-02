#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    
    int res = 0;
    int mx = 0;
    for (int i=1; i*i<=n; ++i) {
        mx = max(mx, i);
        res += (n/i - n/(i+1)) * i;
    }
    for (int i=1; i*i<=n; ++i) {
        if (n/i <= mx) break;
        res += n/i;
    }

    cout << res;
}