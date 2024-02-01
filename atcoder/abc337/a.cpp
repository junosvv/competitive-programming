#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi x(n), y(n);
    FOR(i, 0, n) cin >> x[i] >> y[i];
    int tak = accumulate(x.begin(), x.end(), 0LL);
    int aok = accumulate(y.begin(), y.end(), 0LL);

    if (tak > aok) cout << "Takahashi\n";
    else if (tak < aok) cout << "Aoki\n";
    else cout << "Draw\n";
}