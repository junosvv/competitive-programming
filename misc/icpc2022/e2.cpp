#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    set<int> seen;
    int res = 0;
    FOR(i, 0, n) {
        if (seen.count(a[i])) {
            --res;
            seen.erase(a[i]);
        } else {
            ++res;
            seen.insert(a[i]);
        }
    }

    cout << res;
}