#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n), cnt(101);
    int mx = 0;
    FOR(i, 0, n) {
        cin >> a[i];
        ++cnt[a[i]];
        mx = max(mx, a[i]);
    }

    auto no = [&]() {
        cout << "Impossible";
        exit(0);
    };

    if (mx&1) {
        FOR(i, 1, mx/2 + 1) if (cnt[i]) no();
        if (cnt[mx/2 + 1] != 2) no();
        FOR(i, mx/2 + 2, mx+1) if (cnt[i] < 2) no();
    } else {
        FOR(i, 1, mx/2) {
            if (cnt[i]) no();
        }
        if (cnt[mx/2] != 1) no();
        FOR(i, mx/2 + 1, mx+1) {
            if (cnt[i] < 2) no();
        }
    }

    cout << "Possible";
}