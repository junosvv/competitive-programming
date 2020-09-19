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
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), pos, neg;
        FOR(i, 0, n) {
            cin >> a[i];
            if (a[i] >= 0) pos.push_back(a[i]);
            else neg.push_back(-a[i]);
        }
        if (n == 5) {
            int res = 1;
            FOR(i, 0, 5) res *= a[i];
            cout << res << '\n';
            continue;
        }
        sort(pos.rbegin(), pos.rend());
        sort(neg.rbegin(), neg.rend());

        if (pos.size() == 0) {
            reverse(neg.begin(), neg.end());
            int res = 1;
            FOR(i, 0, 5) res *= neg[i];
            cout << -res << '\n';
        } else {
            int res = -1e18;
            FOR(k, 0, 5) if (!(k&1)) {
                if (k <= neg.size() && 5-k <= pos.size()) {
                    int cur = 1;
                    FOR(i, 0, k) {
                        cur *= neg[i];
                    }
                    FOR(i, 0, 5-k) {
                        cur *= pos[i];
                    }
                    res = max(res, cur);
                }
            }
            cout << res << '\n';
        }
    }
}