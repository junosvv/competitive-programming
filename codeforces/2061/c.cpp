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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int MOD = 998244353;
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n+1);
        FOR(i, 1, n+1) cin >> a[i];

        int c=1, d=a[1]==0;
        FOR(i, 1, n) {
            int e = 0;
            if (a[i] == a[i+1]) e += d;
            if (a[i-1]+1 == a[i+1]) e += c;
            c = d;
            d = e % MOD;
        }
        cout << (c+d) % MOD << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}