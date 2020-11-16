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
    
    int n;
    cin >> n;
    vector<int> a(n), b(n), occ(n+1);
    FOR(i, 0, n) {
        cin >> a[i];
    }
    int k = -1;
    ROF(i, n-1, -1) {
        cin >> b[i];
        if (a[i] == b[i]) {
            k = i;
        }
    }
    if (k != -1) {
        int t = 0;
        int numk = 0;
        FOR(i, 0, n) {
            if (a[i] == b[i]) {
                ++numk;
            } else if (a[i] != a[k] && b[i] != a[k]) {
                ++t;
            }
        }
        if (t < numk) {
            cout << "No" << '\n';
            exit(0);
        }
        FOR(i, 0, n) {
            if (a[i] != a[k] && b[i] != a[k]) {
                swap(b[i], b[k]);
                ++k;
                if (a[k] != b[k]) {
                    break;
                }
            }
        }
    }
    cout << "Yes" << '\n';
    FOR(i, 0, n) {
        cout << b[i] << ' ';
    }
}
