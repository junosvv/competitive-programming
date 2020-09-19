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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), locked(n);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> locked[i];

        vector<int> free;
        FOR(i, 0, n) {
            if (!locked[i]) {
                free.push_back(a[i]);
            }
        }

        sort(free.begin(), free.end());

        vector<int> b(n);
        FOR(i, 0, n) {
            if (locked[i]) {
                b[i] = a[i];
            } else {
                b[i] = free.back();
                free.pop_back();
            }
        }
        FOR(i, 0, n) cout << b[i] << ' ';
        cout << '\n';
    }
}
