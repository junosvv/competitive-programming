#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();

    int res = 0, cl = 0, cr = 0;
    FOR(i, 0, n) {
        if (s[i] == '>') {
            ++cr;
            res += cr;
        } else {
            if (i >= 1 && s[i-1] == '>') {
                res -= min(cl, cr);
                cl = 0;
                cr = 0;
            }
            ++cl;
            res += cl;
        }
    }
    res -= min(cl, cr);
    cout << res;
}