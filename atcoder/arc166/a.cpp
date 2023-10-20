#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

bool minisolve(string s, string t) {
    // cout << "minisolve " << s << ' ' << t << endl;
    int cntA = 0;
    for (char c : t) if (c == 'A') ++cntA;
    for (char c : s) if (c == 'A') --cntA;
    if (cntA < 0) return false;
    for (char& c : s) if (c == 'C') {
        if (cntA > 0) {
            c = 'A';
            --cntA;
        } else {
            c = 'B';
        }
    }
    if (cntA > 0) return false;
    int n = s.size();
    int sA = 0, tA = 0;
    FOR(i, 0, n) {
        if (s[i] == 'A') ++sA;
        if (t[i] == 'A') ++tA;
        if (tA > sA) return false;
    }
    return true;
}

bool solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    
    FOR(i, 0, n) if (t[i] == 'C' && s[i] != 'C') return false;

    s += 'C';
    t += 'C';
    ++n;
    string p, q;
    FOR(i, 0, n) {
        if (t[i] == 'C') {
            if (!minisolve(p, q)) return false;
            p = "";
            q = "";
        } else {
            p += s[i];
            q += t[i];
        }
    }
    return true;
}

signed main() {
    int T;
    cin >> T;
    FOR(ti, 0, T) cout << (solve() ? "Yes\n" : "No\n");
}