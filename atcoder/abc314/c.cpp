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
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    vi a(n);
    FOR(i, 0, n) {
        cin >> a[i];
        --a[i];
    }
    
    vi prev(m, -1);
    ROF(i, n-1, -1) {
        if (prev[a[i]] != -1) swap(s[i], s[prev[a[i]]]);
        prev[a[i]] = i;
    }
    cout << s;
}