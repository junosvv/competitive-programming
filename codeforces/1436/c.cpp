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

int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, x, pos;
    cin >> n >> x >> pos;

    vi a(n);
    FOR(i, 0, n) a[i] = i;
    vi b(n);

    int l = 0;
    int r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] <= pos) {
            l = m + 1;
            b[m] = -1;
        } else {
            r = m;
            b[m] = 1;
        }
    }

    b[pos] = 2;
    int lt = 0;
    int gt = 0;
    FOR(i, 0, n) {
        if (b[i] == 1) ++gt;
        if (b[i] == -1) ++lt;
    }
    int res = 1;
    ROF(i, x-1, x-1-lt) {
        res = res * i % MOD;
    }
    ROF(i, n-x, n-x-gt) {
        res = res * i % MOD;
    }
    FOR(i, 1, n-lt-gt) {
        res = res * i % MOD;
    }
    cout << res << '\n';
}
