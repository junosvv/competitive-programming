#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, const vector<T>& x) {
    os << '[';
    bool first = true;
    for (const T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

bool isprime(int x) {
    for (int d=2; d*d<=x; ++d) {
        if (x%d == 0) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi res(n, 4);
        res[0] = 1;
        int sum = 4*n-3;
        while (!isprime(sum)) {
            res.back() += 2;
            sum += 2;
        }
        FOR(r, 0, n) {
            FOR(c, 0, n) cout << res[(r+c)%n] << ' ';
            cout << '\n';
        }
    }
}
