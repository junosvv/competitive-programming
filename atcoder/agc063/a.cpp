#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    
    vi mark(n+1);
    int mex = 0;

    int ai = 0, bi = 0;
    while (ai <= n && s[ai] == 'B') ++ai;
    while (bi <= n && s[bi] == 'A') ++bi;
    FOR(i, 0, n) {
        if (i&1 && ai <= n) {
            mark[ai] = 1;
            ++ai;
            while (ai <= n && s[ai] == 'B') ++ai;
        }
        if (!(i&1) && bi <= n) {
            mark[bi] = 1;
            ++bi;
            while (bi <= n && s[bi] == 'A') ++bi;
        }
        while (mark[mex]) ++mex;
        
        if (s[mex] == 'A') cout << "Alice\n";
        else cout << "Bob\n";
    }
}