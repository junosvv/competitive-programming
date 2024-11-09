#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int BIG = 4e5 + 2;
    vi sieve(BIG);
    FOR(p, 2, BIG) if (!sieve[p]) {
        sieve[p] = p;
        for (int u = p*p; u<BIG; u+=p) if (!sieve[u]) sieve[u] = p;
    }

    auto check = [&](int p, vi& a) {
        for (int x : a) {
            if (x == p) continue;
            vi facts;
            int xx = x;
            while (sieve[xx]) {
                if (facts.empty() || facts.back() != sieve[xx]) facts.push_back(sieve[xx]);
                xx /= sieve[xx];
            }
            // cout << x << " is ";
            // for (int i : facts) cout << i << ' ';
            // cout << '\n';

            bool succ = false;
            for (int f : facts) {
                int q = (p+f-1)/f*f * 2;
                if (q <= x) {
                    succ = true;
                    // cout << "succ! " << p << " -> " << 2*p << " -> " << q << " -> " << x << '\n';
                    break;
                }
            }
            if (!succ) return false;
        }
        return true;
    };

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        FOR(i, 0, n) {
            if (sieve[a[i]] == a[i]) {
                if (check(a[i], a)) cout << a[i] << '\n';
                else cout << "-1\n";
                return;
            }
        }
        if (check(2, a)) cout << "2\n";
        else cout << "-1\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}