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
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    FOR(i, 0, n) if (a[i] == mx) a[i] = 0;
    cout << *max_element(a.begin(), a.end());
}