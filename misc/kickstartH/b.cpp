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

int f(int x) {
    if (x <= 0) return 0;
    int res = 0;

    int lg = 0;
    int p5 = 1;
    int p10 = 1;
    while (lg < 18 && 10*p10 <= x) {
        ++lg;
        p5 *= 5;
        p10 *= 10;
        res += p5;
    }

    bool odd = 1;
    while (lg >= 0) {
        int d1 = x/p10;
        if ((d1 & 1LL) != odd) {
            res += (d1+1)/2 * p5;
            return res;
        } else {
            res += d1/2 * p5;
        }
        x -= d1*p10;
        odd ^= 1;
        --lg;
        p5 /= 5;
        p10 /= 10;
    }
    return res + 1;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(caset, 1, T+1) {
        int L, R;
        cin >> L >> R;

        cout << "Case #" << caset << ": " << f(R) - f(L-1) << '\n';
    }
}
