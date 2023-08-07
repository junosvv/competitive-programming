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
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    vi b1 = {a[0]}, b2;
    FOR(i, 1, n) {
        if (a[i] != a[i-1]) b1.push_back(a[i]);
        else b2.push_back(a[i]);
    }
    a.clear();
    for (int i : b1) a.push_back(i);
    for (int i : b2) a.push_back(i);

    int i = 0;
    int x = 1;
    while (i < a.size()) {
        if (a[i] != x) {
            a.pop_back();
            if (i >= a.size()) break;
            a.pop_back();
        } else {
            ++i;
        }
        ++x;
    }
    cout << x-1;
}