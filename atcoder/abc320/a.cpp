#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    auto powa = [&](int a, int b) {
        int res = 1;
        FOR(i, 0, b) res *= a;
        return res;
    };

    cout << powa(a, b) + powa(b, a);
}