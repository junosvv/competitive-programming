#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s[0] != s.back()) cout << 1;
    else {
        bool flag = false;
        FOR(i, 2, n-1) if (s[i-1] != s[0] && s[i] != s[0]) {
            cout << 2;
            flag = true;
            break;
        }
        if (!flag) cout << -1;
    }
}