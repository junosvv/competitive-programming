#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>

int n;
vs strings;
int f(int l, int r) {
    // cout << "calling " << l << ' ' << r << endl;
    if (l > r) return 1LL;
    // if (r-l == 2) return 2LL;
    int cnt = 0;
    FOR(i, l, r) {
        if (strings[i] == "if") ++cnt;
        if (strings[i] == "endif") --cnt;
        if (cnt == 0) return max(f(l, i), f(i+1, r));
    }
    cnt = 0;
    FOR(i, l, r) {
        if (strings[i] == "if") ++cnt;
        if (strings[i] == "endif") --cnt;
        if (cnt == 1 && strings[i] == "else") return f(l+1, i-1) + f(i+1, r-1);
    }
    assert(false);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    strings.assign(n, "");
    FOR(i, 0, n) cin >> strings[i];

    cout << f(0, n-1) << '\n';
}