#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    priority_queue<pii, vector<pii>, greater<pii>> q;
    vi buys(n);
    int res = 0;
    FOR(i, 0, n) {
        q.emplace(a[i], i);
        if (q.top().first < a[i]) {
            ++buys[q.top().second];
            --buys[i];
            res += a[i] - q.top().first;
            if (buys[q.top().second] >= 1) q.pop(); // cant buy it more than once
        }
    }
    cout << res;
}