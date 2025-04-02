#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    int k = (n+1)/2;
    FOR(i, 0, k) {
        cout << a[k-i-1] << ' ';
        if (k+i < n) cout << a[k+i] << ' ';
    }
}