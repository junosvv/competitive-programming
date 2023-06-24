#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    vi a = {0, 3, 4, 8, 9, 14, 23};
 
    char p, q;
    cin >> p >> q;
 
    cout << abs(a[q-'A'] - a[p-'A']);
}