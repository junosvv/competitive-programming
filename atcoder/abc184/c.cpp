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

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if (r1 == r2 && c1 == c2) cout << 0;
    else if (r1+c1 == r2+c2 || r1-c1 == r2-c2 || abs(r1-r2) + abs(c1-c2) <= 3) cout << 1;
    else if ((r1+c1&1) == (r2+c2&1)) cout << 2;
    else if (abs(r1+c1-r2-c2) <= 3 || abs(r1-c1-r2+c2) <= 3) cout << 2;
    else cout << 3;
}
