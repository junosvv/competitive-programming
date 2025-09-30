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
    
    int T, P, C;
    cin >> T >> P >> C;
    vi diff(P), sheep(C), mult(C);
    vvi prefs(C, vi(P));
    FOR(p, 0, P) cin >> diff[p];
    FOR(c, 0, C) {
        string s;
        cin >> s >> mult[c];
        if (s == "baa") sheep[c] = true;
        FOR(p, 0, P) {
            cin >> prefs[c][p];
            --prefs[c][p];
        }
    }

    vi poss(P), busy(C), upto(C);
    vvi res(C, vi(P)), eventsC(T), eventsP(T);
    FOR(t, 10, T) {
        for (int c : eventsC[t]) busy[c] = false;
        FOR(c, 0, C) if (!busy[c]) {
            for (int p : prefs[c]) if (res[c][p] == 0 && (!sheep[c] || poss[p])) {
                busy[c] = true;
                int solveTime = t + diff[p] * mult[c];
                if (solveTime < T) {
                    res[c][p] = solveTime;
                    eventsC[solveTime].push_back(c);
                    eventsP[solveTime].push_back(p);
                }
                break;
            }
        }
        for (int p : eventsP[t]) poss[p] = true;
    }
    FOR(c, 0, C) {
        FOR(p, 0, P) cout << res[c][p] << ' ';
        cout << '\n';
    }
}