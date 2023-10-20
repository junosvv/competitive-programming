#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(2*n);
    FOR(i, 0, 2*n) cin >> a[i];
    int res = accumulate(a.begin(), a.end(), 0LL);

    priority_queue<int,vi,greater<int>> pq;
    FOR(i, 0, n) {
        pq.push(a[n-1-i]);
        pq.push(a[n+i]);
        res -= pq.top();
        pq.pop();
    }
    cout << res;
}