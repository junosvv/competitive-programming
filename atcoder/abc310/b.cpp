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

    vi p(n);
    vvi f(n);
    FOR(i, 0, n) {
        int k;
        cin >> p[i] >> k;
        FOR(j, 0, k) {
            int x;
            cin >> x;
            f[i].push_back(x);
        }
    }

    auto contains = [&](vi a, int u) {
        for (int i : a) if (u == i) return true;
        return false;
    };

    auto subset = [&](vi a, vi b) {
        for (int u : a) if (!contains(b, u)) return false;
        return true;
    };

    FOR(i, 0, n) FOR(j, 0, n) if (p[i] <= p[j] && subset(f[j], f[i]) && (p[i] < p[j] || f[i].size() > f[j].size())) {
        cout << "Yes";
        exit(0);
    }
    cout << "No";
}