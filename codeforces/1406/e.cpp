#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

int query(char c, int x) {
    string s(1, c);
    s += ' ';
    s += to_string(x);
    cout << s << endl;
    int n;
    cin >> n;
    return n;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> sieve(n+1), primes;
    FOR(p, 2, n+1) if (!sieve[p]) {
        primes.push_back(p);
        for (int u=p; u<n+1; u+=p) sieve[u] = p;
    }
    reverse(primes.begin(), primes.end());
    
    vector<int> facts;
    const int S = 100;
    vector<bool> sieve2(n+1);
    int elts = n;

    auto check = [&](int i) {
        if (elts != query('A', 1)) {
            FOR(j, i/S*S, i+1) {
                if (query('A', primes[j])) facts.push_back(primes[j]);
            }
            return true;
        }
        return false;
    };

    FOR(i, 0, primes.size()) {
        int p = primes[i];
        if (p <= n/p) {
            check(i-1);
            break;
        }
        query('B', p);
        for (int u=p; u<n+1; u+=p) {
            if (!sieve2[u]) {
                sieve2[u] = true;
                --elts;
            }
        }
        if ((i+1) % S == 0) {
            if (check(i)) break;
        }
        if (i+1 == primes.size()) check(i);
    }

    FOR(j, 0, primes.size()) {
        int p = primes[j];
        if (p > n/p) continue;
        query('B', p);
        if (query('A', p)) {
            facts.push_back(p);
        }
    }
    
    int res = 1;
    for (int p : facts) {
        int q = p;
        while (q <= n/p && query('A', q*p)) {
            q *= p;
        }
        res *= q;
    }
    cout << "C " << res << endl;
}