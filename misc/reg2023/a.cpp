#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, K;
    cin >> n >> K;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    auto name = [&](int turn) {
        return (turn ? "Bertha" : "Aaron");
    };

    int turn = 0;
    for (int i=n-1; i>=0; i-=2) {
        if (a[i] % (K+1) == 1) turn ^= 1;
        else if (a[i] % (K+1) != 0) {
            cout << name(turn) << '\n';
            exit(0);
        }
    }
    cout << name(!turn) << '\n';
}