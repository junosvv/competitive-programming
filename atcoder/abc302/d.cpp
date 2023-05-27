#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++(i))
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, d;
    cin >> n >> m >> d;
    vi a(n), b(m);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    int i=0, j=0;
    while (i<n && j<m) {
        if (a[i] > b[j]+d) ++i;
        else if (b[j] > a[i]+d) ++j;
        else {
            cout << a[i]+b[j];
            exit(0);
        }
    }
    cout << -1;
}