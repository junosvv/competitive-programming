#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long
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
    
    map<lg, pair<int,int>> mp;
    lg pi = 1;
    FOR(i, 1, 1e9) {
        pi *= 3;
        if (pi > 1e18) break;
        lg pj = 1;
        FOR(j, 1, 1e9) {
            pj *= 5;
            if (pi+pj > 1e18) break;
            mp[pi+pj] = {i, j};
        }
    }

    lg n;
    cin >> n;
    if (mp.count(n)) {
        cout << mp[n].first << ' ' << mp[n].second;
    } else {
        cout << -1;
    }
}
