#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pii pair<int,int>

bool chk(char x, char y) {
    return x == 'A' && y == 'B' || x == 'B' && y == 'C' || x == 'C' && y == 'A';
}

string canon(string s) {
    int n = s.size();
    string ss;
    FOR(i, 0, n) {
        ss += s[i];
        int m = ss.size();
        if (m >= 3 && chk(ss[m-3], ss[m-2]) && chk(ss[m-2], ss[m-1]) && chk(ss[m-1], ss[m-3])) {
            FOR(i, 0, 3) ss.pop_back();
        }
    }
    return ss;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (canon(s) == canon(t)) cout << "YES";
    else cout << "NO";
}