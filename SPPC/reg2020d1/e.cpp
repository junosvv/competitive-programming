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
    vi sieve(BIG), primes;
    FOR(p, 2, BIG) if (!sieve[p]) {
        primes.push_back(p);
        for (int u=p; u<BIG; u+=p) sieve[u] = p;
    }
    cout << primes.size() << '\n';
    vi primes_all = primes, primes_new = primes;
    FOR(p, 0, primes.size()) {
        int k=p;
        for (int js=primes.size(); js>=1; js/=2) {
            while (k+js < primes.size() && primes[p]*primes[k+js] < a) k += js;
        }
        ++k;
        FOR(q, k, primes.size()) {
            int u = primes[p]*primes[q];
            if (u > b) break;
            primes2.push_back(u);
            primes_all.push_back(primes[pp]);
        }
    }
    cout << primes2.size() << '\n';
}