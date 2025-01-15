#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();
    int cons = 0, vows = 0, ys = 0, ns = 0, gs = 0;
    for (char c : s) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') ++vows;
        else if (c != 'Y') ++cons;
        else ++ys;
        if (c == 'N') ++ns;
        if (c == 'G') ++gs;
    }
    int pairs = min(ns, gs);
    
    int res = 0;
    FOR(v, 0, vows+ys+1) {
        int ccons = cons + ys - max(0LL, v-vows);
        if (ccons < 2*v) continue;
        res = max(res, 3*v + min(min(2*v, pairs), ccons-2*v));
    }
    cout << res;
}