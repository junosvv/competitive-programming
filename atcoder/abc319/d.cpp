#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    auto check = [&](int k) {
        if (k < *max_element(a.begin(), a.end())) return false;
        int row = 0;
        int col = 0;
        FOR(i, 0, n) {
            if (col + a[i] > k) {
                ++row;
                col = 0;
            }
            col += a[i] + 1;
        }
        return row < m;
    };

    int k = 1e15;
    for (int b=1e15; b>=1; b/=2) {
        while (check(k-b)) k -= b;
    }
    cout << k;
}