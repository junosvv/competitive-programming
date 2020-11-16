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
    
    int n, k;
    cin >> n >> k;

    k = abs(k);
    
    auto f = [&](int x) {
        return min(n, x-1) - max(1, x-n) + 1;
    };

    lg res = 0;
    FOR(t, k+2, 2*n+1) {
        res += (lg)f(t)*f(t-k);
    }
    cout << res << '\n';
}
