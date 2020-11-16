#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long
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
    
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 0) {
        cout << 1 << ' ' << 2 << '\n';
        exit(0);
    }

    if (m < 0 || m >= n-1) {
        cout << -1 << '\n';
        exit(0);
    }

    int k = 1;
    FOR(i, 0, n-2-m) {
        cout << k << ' ';
        ++k;
        cout << k << '\n';
        ++k;
    }
    cout << k << ' ' << k+2*m+3 << '\n';
    ++k;
    FOR(i, 0, m+1) {
        cout << k << ' ';
        ++k;
        cout << k << '\n';
        ++k;
    }
}
