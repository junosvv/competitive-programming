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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    int xs = 0;
    FOR(i, 0, n) {
        cin >> a[i];
        xs ^= a[i];
    }
    if (!(n&1) && xs != 0) {
        cout << "NO" << '\n';
        exit(0);
    }

    cout << "YES" << '\n';
    vector<vi> ops;
    for (int i=1; i+2<=n; i+=2) ops.push_back({i, i+1, i+2});
    for (int i=1; i+2<=n; i+=2) ops.push_back({i, i+1, n&1 ? n : n-1});

    cout << ops.size() << '\n';
    for (vi &x : ops) {
        FOR(i, 0, 3) cout << x[i] << ' ';
        cout << '\n';
    }
}
