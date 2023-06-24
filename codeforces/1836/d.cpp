#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    FOR(i, 0, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
 
    vi cnt(n);
    int prev = n-1;
    ROF(i, n-1, -1) {
        if (a[i] != a[prev]) prev = i;
        ++cnt[prev];
    }
    
    int best = 0, bestVal = 0;
    auto check = [&](int x, int i) {
        if (0 <= x && x <= m) {
            int leftIdx = i-k+1;
            int rightIdx = i+k;
            if (x == a[i]) rightIdx -= cnt[i];
            if (rightIdx < 0) return;
            int L = leftIdx < 0 ? 0 : (a[leftIdx] + x) / 2 + 1;
            int R = rightIdx >= n ? m : (a[rightIdx] + x + 1) / 2 - 1;
            int val = max(0LL, R-L+1);
            // cout << x << " (" << i << ") returns: " << val << " (" << L << ", " << R << ")\n";
            if (val > bestVal) {
                best = x;
                bestVal = val;
            }
        }
    };
 
    if (a[0] >= 2) {
        check(0, -1);
        check(1, -1);
    }
    FOR(i, 0, n) {
        FOR(x, a[i]-2, a[i]) {
            if (i == 0 || x >= a[i-1]) {
                check(x, i-1);
            }
        }
        FOR(x, a[i], a[i]+3) {
            if (i == n-1 || x < a[i+1]) {
                check(x, i);
            }
        }
    }
 
    cout << bestVal << ' ' << best;
}