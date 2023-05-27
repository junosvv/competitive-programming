#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++(i))
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) {
        cin >> a[i];
        --a[i];
    }
    vi b = a;
    sort(b.begin(), b.end());

    vector<vi> cnt(4, vi(4));
    int res = 0;
    FOR(i, 0, n) if (a[i] != b[i]) {
        if (cnt[b[i]][a[i]]) {
            --cnt[b[i]][a[i]];
            ++res;
        } else ++cnt[a[i]][b[i]];
    }

    FOR(i, 0, 4) FOR(j, i+1, 4) FOR(k, i+1, 4) if (i != j && j != k && i != k) {
        int t = min(cnt[i][j], min(cnt[j][k], cnt[k][i]));
        res += 2*t;
        cnt[i][j] -= t;
        cnt[j][k] -= t;
        cnt[k][i] -= t;
    }

    int sm = 0;
    FOR(i, 0, 4) FOR(j, 0, 4) sm += cnt[i][j];
    res += 3*sm/4;
    cout << res;
}
