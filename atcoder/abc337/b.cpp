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
    int n = s.size();

    string t = string(1, s[0]);
    FOR(i, 1, n) {
        if (s[i] != s[i-1]) t.push_back(s[i]);
    }
    if (t == "A" || t == "B" || t == "C" || t == "AB" || t == "AC" || t == "BC" || t == "ABC") cout << "Yes";
    else cout << "No";
}