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
    const int INF = 1e5+2;
    vi a(n), cnt(INF);
    FOR(i, 0, n) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    ROF(i, INF-1, -1) {
        if (cnt[i] == i) {
            cout << i << '\n';
            break;
        }
    }
}