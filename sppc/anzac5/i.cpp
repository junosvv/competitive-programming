#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define lg long long

int getd(int x, int d) {
    while (d) {
        x /= 3;
        --d;
    }
    return x%3;
}

int n;
int calc(vi& xlocs) {
    int nx = xlocs.size();
    set<int> xlocset;
    for (int i : xlocs) xlocset.insert(i);
    int res = 0;
    set<pii> answers;
    FOR(a, 0, nx) FOR(b, 0, nx) if (a != b) {
        bool failed = false;
        FOR(d, 0, n) {
            int ad = getd(xlocs[a], d);
            int bd = getd(xlocs[b], d);
            if (abs(ad-bd) == 2 || (ad == 1 && bd != 1)) {
                failed = true;
            }
        }
        if (failed) continue;
        int c = 0;
        int tk = 1;
        FOR(d, 0, n) {
            int ad = getd(xlocs[a], d);
            int bd = getd(xlocs[b], d);
            if (ad == bd) c += ad*tk;
            else c += (3-ad-bd)*tk;
            tk *= 3;
        }
        if (xlocset.count(c)) {
            vi temp = {xlocs[a], xlocs[b], c};
            sort(temp.begin(), temp.end());
            // cout << "found: " << xlocs[a] << ' ' << xlocs[b] << ' ' << c << '\n';
            answers.emplace(temp[0], temp[1]);
        }
    }
    // for (pii pr : answers) cout << pr.first << ' ' << pr.second << '\n';
    // cout << '\n';
    return answers.size();
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    while (true) {
        cin >> n;
        if (n == 0) break;
        int p = pow(3, n);
        string grid(p, ' ');
        vi xlocs, olocs;
        FOR(i, 0, p) {
            cin >> grid[i];
            if (grid[i] == 'X') xlocs.push_back(i);
            else if (grid[i] == 'O') olocs.push_back(i);
        }
        cout << "X scores " << calc(xlocs) << " and O scores " << calc(olocs) << '\n';
    }
}

/*
2
XXX
XXX
XXX
0
*/