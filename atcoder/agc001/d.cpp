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
    
    int n, m;
    cin >> n >> m;
    vi a(m), odds, evens;
    FOR(i, 0, m) {
        cin >> a[i];
        if (a[i]&1) odds.push_back(a[i]);
        else evens.push_back(a[i]);
    }

    if (odds.size() >= 3) {
        cout << "Impossible";
        exit(0);
    }

    vi b;
    if (m == 1) b = {1, a[0]-1};
    else {
        a.clear();
        if (!odds.empty()) a.push_back(odds[0]);
        for (int i : evens) a.push_back(i);
        if (odds.size() == 2) a.push_back(odds[1]);
        assert(a.size() == m);

        b = a;
        ++b[0];
        --b.back();
    }

    if (b.back() == 0) b.pop_back();

    for (int i : a) cout << i << ' ';
    cout << '\n' << b.size() << '\n';
    for (int i : b) cout << i << ' ';
}