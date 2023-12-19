#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    if (a > 0 && b > 0) cout << "Positive";
    else if (a < 0 && b < 0) {
        if ((a+b)&1) cout << "Positive";
        else cout << "Negative";
    } else cout << "Zero";
}