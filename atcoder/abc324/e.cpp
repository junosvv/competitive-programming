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
    string t;
    cin >> n >> t;
    vector<string> strings(n);
    FOR(i, 0, n) cin >> strings[i];

    vi a(n), b(n);
    FOR(i, 0, n) {
        for (int c : strings[i]) if (a[i] < t.size() && c == t[a[i]]) ++a[i];
        reverse(strings[i].begin(), strings[i].end());
        for (int c : strings[i]) if (b[i] < t.size() && c == t[(int)t.size() - 1 - b[i]]) ++b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = n;
    int res = 0;
    FOR(i, 0, n) {
        while (j-1 >= 0 && a[i] + b[j-1] >= t.size()) --j;
        res += n-j;
    }
    cout << res;
}