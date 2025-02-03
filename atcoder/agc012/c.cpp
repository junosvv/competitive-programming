#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

const int MOD = 1e9 + 7;
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}
#define inv(x) powa(x, MOD-2)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    ++n;

    int t = 0;
    vi pref, suff;
    ROF(d, 60, -1) {
        if (t == 0) {
            if (!(n>>d&1LL)) continue;
            t = 1;
        } else {
            suff.push_back(t++);
            if (n>>d&1LL) {
                pref.push_back(t++);
            }
        }
    }
    reverse(pref.begin(), pref.end());
    cout << 2*(t-1) << '\n';
    for (int i : pref) cout << i << ' ';
    for (int i : suff) cout << i << ' ';
    FOR(i, 1, t) cout << i << ' ';
    cout << '\n';

    // vi x = pref;
    // for (int i : suff) x.push_back(i);
    // assert(x.size() == t-1);

    // int cnt = 0;
    // FOR(mask, 1, 1<<t-1) {
    //     int prev = 0;
    //     bool fail = false;
    //     FOR(d, 0, t-1) if (mask>>d&1LL) {
    //         if (x[d] <= prev) {
    //             fail = true;
    //             break;
    //         }
    //         prev = x[d];
    //     }
    //     if (!fail) ++cnt;
    // }
    // cout << "res: " << cnt << '\n';
}