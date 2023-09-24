#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    vi a;
    FOR(mask, 2, 1024) {
        string s;
        ROF(d, 9, -1) if (mask>>d&1LL) s += '0'+d;
        int x = stoll(s);
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    
    int k;
    cin >> k;
    --k;
    cout << a[k];
}