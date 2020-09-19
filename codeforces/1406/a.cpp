#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

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
        vector<int> a(n);
        FOR(i, 0, n) cin >> a[i];

        const int BIG = 105;
        vector<int> occ(BIG);
        FOR(i, 0, n) {
            ++occ[a[i]];
        }

        int x=0, y=0;
        bool both = true;
        FOR(i, 0, BIG) {
            if (both) {
                if (occ[i] >= 2) {
                    ++x;
                    ++y;
                } else if (occ[i] == 1) {
                    ++x;
                    both = false;
                } else break;
            } else {
                if (occ[i] >= 1) {
                    ++x;
                } else {
                    break;
                }
            }
        }
        cout << x+y << '\n';
    }
}