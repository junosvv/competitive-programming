#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

const int MOD = 998244353;
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1LL) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}
#define inv(x) powa(x, MOD-2)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        int sm = accumulate(a.begin(), a.end(), 0LL);
        a.push_back(-1e16);
        ++n;

        vi b, nw;
        int cur = 0;
        int wiggle = 1e16;
        int dec = 0;
        FOR(i, 0, n) {
            if (cur+a[i] > sm) {
                b.push_back(-cur); // -ve
                nw.push_back(b.size());
                cur = 0;
            } else if (cur+a[i] < 0) {
                if (!nw.empty()) {
                    b[nw.back()] = wiggle;
                    dec += wiggle;
                }
                b.push_back(-a[i]-cur); // +ve
                nw.push_back(b.size());
                cur = -a[i];
            }
            cur += a[i];
            if (!nw.empty()) wiggle = min(wiggle, b[nw.back()]+sm-cur);
            b.push_back(a[i]);
        }
        cout << "finished: ";
        for (int i : b) cout << i << ' ';
        cout << '\n';
        cout << dec << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}