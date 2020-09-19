#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

long long MOD = 1e9+7;

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (auto i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i, 0, n) cin >> a[i];

    const int BIG = 2e5+5;
    vector<int> sieve(BIG), primes;
    FOR(p, 2, BIG) if (!sieve[p]) {
        primes.push_back(p);
        for (int u=p; u<BIG; u+=p) sieve[u] = p;
    }

    vector<int> occ(BIG), cnt(BIG);
    vector<vector<int>> mins(BIG, vector<int>(2, 1e9));
    FOR(i, 0, n) if (a[i] != 1) {
        int x = a[i];
        vector<int> facts;
        while (x != 1) {
            ++occ[sieve[x]];
            facts.push_back(sieve[x]);
            x /= sieve[x];
        }
        for (int p : facts) if (occ[p]) {
            ++cnt[p];
            mins[p].push_back(occ[p]);
            sort(mins[p].begin(), mins[p].end());
            mins[p].resize(2);
            occ[p] = 0;
        }
    }

    int res = 1;
    for (int p : primes) {
        if (cnt[p] == n-1 && mins[p][0] != 1e9) {
            res *= pow(p, mins[p][0]);
        } else if (cnt[p] == n && mins[p][1] != 1e9) {
            res *= pow(p, mins[p][1]);
        }
    }

    cout << res << '\n';
}
