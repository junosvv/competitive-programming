#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    multiset<int> L, R;

    int q;
    cin >> q;
    FOR(qi, 0, q) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == '+') {
            L.insert(l);
            R.insert(r);
        } else {
            L.erase(L.find(l));
            R.erase(R.find(r));
        }
        cout << (!R.empty() && *R.begin() < *L.rbegin() ? "YES" : "NO") << '\n';
    }
}