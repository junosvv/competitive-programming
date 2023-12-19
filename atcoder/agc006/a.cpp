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
    string s, t;
    cin >> n >> s >> t;

    auto check = [&](string t, string w) {
        FOR(i, 0, n) {
            if (t[i] != w[w.size()-n+i]) return false;
        }
        return true;
    };

    ROF(i, n, -1) {
        string w = s;
        FOR(j, i, n) w += t[j];
        if (check(t, w)) {
            cout << 2*n-i;
            break;
        }
    }
}