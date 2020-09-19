#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)

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

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        bool sawk = false;
        FOR(i, 0, n) {
            cin >> a[i];
            if (a[i] == k) sawk = true;
            a[i] = a[i] >= k;
        }
        if (!sawk) {
            cout << "no" << '\n';
            continue;
        }
        if (n == 1) {
            cout << "yes" << '\n';
            continue;
        }
        if (n == 2) {
            cout << (a[0] + a[1] == 2 ? "yes" : "no") << '\n';
            continue;
        }
        bool yes = false;
        FOR(i, 2, n) {
            if (a[i-2] + a[i-1] + a[i] >= 2) {
                yes = true;
                break;
            }
        }
        cout << (yes ? "yes" : "no") << '\n';
    }
}