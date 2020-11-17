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
        int n, m;
        cin >> n >> m;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        cout << (accumulate(a.begin(), a.end(), 0LL) == m ? "YES" : "NO") << '\n';
    }
}
