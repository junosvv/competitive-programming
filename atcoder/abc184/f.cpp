#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, t;
    cin >> n >> t;

    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    vi b = a;
    b.resize(n/2);
    
    int m = (n+1)/2 + 1;
    vi p2(m, 1);
    FOR(i, 1, m) p2[i] = 2 * p2[i-1];

    auto solve = [&](vi &res) {
        FOR(mask, 0, p2[b.size()]) {
            int sum = 0;
            FOR(d, 0, b.size()) {
                if (mask>>d&1LL) {
                    sum += b[d];
                    if (sum > t) break;
                }
            }
            if (sum <= t) res.push_back(sum);
        }
        sort(res.begin(), res.end());
    };

    vi res1, res2;
    solve(res1);
    b.clear();
    FOR(i, n/2, n) b.push_back(a[i]);
    solve(res2);

    int j = res2.size() - 1;
    int ans = 0;
    FOR(i, 0, res1.size()) {
        while (res1[i] + res2[j] > t) --j;
        ans = max(ans, res1[i] + res2[j]);
    }
    cout << ans;
}
