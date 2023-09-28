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
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    const int BIG = 1e6+1;
    vi sieve(BIG);
    FOR(p, 2, BIG) if (!sieve[p]) for (int u=p; u<BIG; u+=p) sieve[u] = p;

    auto cnt = [&](int l, int r, int k) {
        int ll = (l+k-1)/k*k;
        if (ll > r) return 0LL;
        return (r-ll) / k + 1;
    };

    auto check = [&](int n) {
        vi facts;

        int n0 = n;
        if (n >= BIG) {
            for (int d=2; d*d<=n; ++d) {
                if (n%d == 0) {
                    facts.push_back(d);
                    n /= d;
                    if (n%d == 0) return 0LL;
                }
            }
            if (n >= BIG) {
                facts.push_back(n);
                n = 1;
            }
        }
        while (sieve[n]) {
            facts.push_back(sieve[n]);
            n /= sieve[n];
            if (sieve[n] == facts.back()) return 0LL;
        }
        n = n0;

        int sign = facts.size()&1 ? -1 : 1;
        // if (sign*cnt(a,b,n)*cnt(c,d,n)) cout << n << " adding " << sign * cnt(a, b, n) * cnt(c, d, n) << endl;
        return sign * cnt(a, b, n) * cnt(c, d, n);
    };

    int res = 0;
    FOR(n, 2, BIG) res += check(n);
    FOR(n, max(BIG, a), b+1) res += check(n);
    cout << (b-a+1)*(d-c+1) + res;
}