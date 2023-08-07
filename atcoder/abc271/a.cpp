#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;

    function<char(int)> conv = [&](int x) {
        if (x <= 9) return '0'+x;
        else return 'A'+x-10;
    };

    cout << conv(n/16) << conv(n%16);
}