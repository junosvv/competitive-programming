#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    int sm = accumulate(a.begin(), a.end(), 0LL);
    int lower = sm / n;
    int numhigher = sm % n;
    vi b(n);
    FOR(i, 0, n-numhigher) b[i] = lower;
    FOR(i, n-numhigher, n) b[i] = lower+1;

    int res = 0;
    FOR(i, 0, n) res += abs(b[i] - a[i]);
    cout << res / 2;
}