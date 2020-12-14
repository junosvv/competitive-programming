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

    int n;
    cin >> n;

    auto check = [&](int k) {
        return k*(k+1)/2 <= n+1;
    };

    int k = 0;
    int upp = 2e9;
    for (int b=upp; b>=1; b/=2) {
        while (k+b <= upp && check(k+b)) k += b;
    }
    cout << n-k+1 << '\n';
}
