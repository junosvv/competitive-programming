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
    sort(a.begin(), a.end(), greater<int>());
    
    FOR(i, 0, n-1) {
        if (a[i+1] <= i+1) {
            vi b;
            FOR(j, i, n) {
                if (a[j] <= i) break;
                b.push_back(a[j] - i);
            }
            if (!(b[0]&1) || !(b.size()&1)) cout << "First";
            else cout << "Second";
            exit(0);
        }
    }
    if (!(a.back()+n & 1LL)) cout << "Second";
    else cout << "First";
}