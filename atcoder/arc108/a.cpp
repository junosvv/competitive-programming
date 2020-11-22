#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
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

    int s, p;
    cin >> s >> p;

    for (int d=1; d*d<=p; ++d) {
        if (p%d == 0 && d + p/d == s) {
            cout << "Yes" << '\n';
            exit(0);
        }
    }
    cout << "No" << '\n';
}
