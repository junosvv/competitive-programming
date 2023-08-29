#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vi a(n+m);
    map<int,int> buy, sell;
    FOR(i, 0, n) {
        cin >> a[i];
        ++sell[a[i]];
    }
    FOR(i, 0, m) {
        cin >> a[n+i];
        ++a[n+i];
        ++buy[a[n+i]];
    }
    sort(a.begin(), a.end());
    
    int nbuy = m, nsell = 0;
    FOR(i, 0, n+m) {
        nbuy -= buy[a[i]];
        nsell += sell[a[i]];
        buy[a[i]] = 0;
        sell[a[i]] = 0;
        if (nsell >= nbuy) {
            cout << a[i];
            break;
        }
    }
}