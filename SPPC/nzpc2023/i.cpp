// i.cpp
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
    vi a(n);
    map<int,int> cnt;
    int k = 0;
    FOR(i, 0, n) {
        cin >> a[i];
        ++cnt[a[i]];
        k = max(k, cnt[a[i]]);
    }
    sort(a.begin(), a.end());

    cout << k << '\n';
    vvi res(k);
    FOR(i, 0, n) {
        res[i%k].push_back(a[i]);
    }
    FOR(i, 0, k) {
        for (int j : res[i]) cout << j << ' ';
        cout << '\n';
    }
}