#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long
#define vi vector<int>

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
    vi a(n);
    FOR(i, 0, n) {
        cin >> a[i];
        --a[i];
    }

    vi dp(n);
    FOR(i, 0, n) {
        dp[a[i]] = a[i] ? dp[a[i] - 1] + 1 : 1;
    }
    cout << n - *max_element(dp.begin(), dp.end());
}
