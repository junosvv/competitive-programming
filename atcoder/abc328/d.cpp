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
    
    string s;
    cin >> s;
    string t;
    for (char c : s) {
        t += c;
        while (t.size() >= 3) {
            int n = t.size();
            if (!(t[n-3] == 'A' && t[n-2] == 'B' && t[n-1] == 'C')) break;
            FOR(i, 0, 3) t.pop_back();
        }
    }
    cout << t;
}