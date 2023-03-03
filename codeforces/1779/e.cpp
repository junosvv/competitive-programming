#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;

    vector<pii> prs(n);
    FOR(i, 0, n) {
        prs[i].second = i;
        cout << "? " << i+1 << ' ';
        FOR(j, 0, n) cout << (j != i);
        cout << endl;
        cin >> prs[i].first;
    }

    sort(prs.rbegin(), prs.rend());
    int k = 1;
    FOR(i, 1, n) {
        cout << "? " << prs[i].second+1 << ' ';
        vi out(n);
        FOR(j, 0, k) out[prs[j].second] = 1;
        FOR(j, 0, n) cout << out[j];
        cout << endl;
        int x;
        cin >> x;
        if (x) k = i+1;
    }
    
    vi out(n);
    FOR(j, 0, k) out[prs[j].second] = 1;
    cout << "! ";
    FOR(j, 0, n) cout << out[j];
    cout << endl;
}