#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long

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

    int sum = 0;
    vector<int> diff(n);
    diff[0] = a[0];
    FOR(i, 1, n) diff[i] = a[i] - a[i-1];
    FOR(i, 1, n) if (diff[i] > 0) sum += diff[i];

    auto f = [&]() {
        int k = sum + diff[0] + 1;
        cout << (k >> 1) << '\n';
    };

    f();

    int q;
    cin >> q;
    FOR(qi, 0, q) {
        int l, r, x;
        cin >> l >> r >> x;
        if (l-1 && diff[l-1] > 0) sum -= diff[l-1];
        diff[l-1] += x;
        if (l-1 && diff[l-1] > 0) sum += diff[l-1];
        if (r < n) {
            if (r && diff[r] > 0) sum -= diff[r];
            diff[r] -= x;
            if (r && diff[r] > 0) sum += diff[r];
        }
        f();
    }
}