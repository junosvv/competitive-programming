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

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        FOR(i, 0, n) cout << 1 << ' ';
        cout << '\n';
    }
}
