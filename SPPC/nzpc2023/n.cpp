// n.cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int nl, nr;
    cin >> nl >> nr;
    int n = (nr-nl+2)/2;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    int l = -1, r = -1;
    int ll = (-nl) / 2;
    int rr = ll+1;
    while (ll >= 0 && rr < n) {
        if (a[ll] < a[rr]) --ll;
        else if (a[rr] < a[ll]) ++rr;
        else { // a[ll] == a[rr]
            l = ll; r = rr;
            while (ll >= 0 && a[ll] <= a[l]) --ll;
            while (rr < n && a[rr] <= a[r]) ++rr;
            if (ll >= 0 && rr < n) {
                l = -1; r = -1;
            }
        }
    }

    auto f = [&](int l) {
        int mx = a[0];
        int res = 0;
        FOR(i, 1, l+1) {
            res += mx;
            mx = max(mx, a[i]);
        }
        return res;
    };
    auto g = [&](int r) {
        int mx = a[n-1];
        int res = 0;
        ROF(i, n-2, r-1) {
            res += mx;
            mx = max(mx, a[i]);
        }
        return res;
    };

    int res = 0;
    if (l == -1) {
        if (ll < 0) res = f(rr);
        else if (rr >= n) res = g(ll);
    } else {
        res = 1e16;
        if (ll < 0) res = min(res, f(l));
        if (rr >= n) res = min(res, g(r));
        // cout << "interval " << l << ' ' << r << '\n';
        // cout << "mini res " << res << '\n';
        res *= 2;
        res += (r-l) * a[l];
    }
    // if (ll < 0) {
    //     // cout << "flow left ";
    //     if (l == -1) {
    //         // cout << "no mid" << endl;
    //         res = f(rr);
    //     } else {
    //         // cout << "mid" << endl;
    //         res = 2*f(l) + (r-l)*a[l];
    //     }
    // } else if (rr >= n) {
    //     // cout << "flow right ";
    //     if (l == -1) {
    //         // cout << "no mid" << endl;
    //         res = g(ll);
    //     } else {
    //         // cout << "mid" << endl;
    //         res = 2*g(r) + (r-l)*a[l];
    //     }
    // }
    cout << 2*res << endl;
}
