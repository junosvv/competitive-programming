#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, q;
    string s;
    cin >> n >> q >> s;
    vi trans(n);
    FOR(i, 1, n) trans[i] = trans[i-1] + (s[i] != s[i-1]);

    FOR(i, 0, q) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int k = trans[r] - trans[l];
        cout << k/2 + (k&1 || s[l] != s[r]) << '\n';
    }
}