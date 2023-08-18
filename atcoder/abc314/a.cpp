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
    
    string s = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    int n;
    cin >> n;
    cout << "3.";
    FOR(i, 0, n) cout << s[i];
}