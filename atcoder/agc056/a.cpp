#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pii pair<int,int>

int n;
vs res;
vi row, col;
bool done;
void search(int r, int c) {
    if (r == n) {
        bool good = true;
        FOR(cc, 0, c) {
            if (col[cc] != 3) good = false;
        }
        if (good) {
            int comps = 0;
            vector<vb> seen(n, vb(n));
            FOR(sr, 0, n) FOR(sc, 0, n) if (res[sr][sc] == '#' && !seen[sr][sc]) {
                ++comps;
                seen[sr][sc] = true;
                vector<pii> q = {{sr, sc}};
                int qi = 0;
                while (qi < q.size()) {
                    int ur, uc;
                    tie(ur, uc) = q[qi++];
                    for (pii delta : vector<pii>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                        int rr = ur + delta.first, cc = uc + delta.second;
                        if (0 <= rr && rr < n && 0 <= cc && cc < n && res[rr][cc] == '#' && !seen[rr][cc]) {
                            seen[rr][cc] = true;
                            q.emplace_back(rr, cc);
                        }
                    }
                }
            }
            if (comps == n) {
                done = true;
            }
        }
    } else if (c == n) {
        if (row[r] == 3) search(r+1, 0);
    } else {
        if (row[r] < 3 && col[c] < 3) {
            ++row[r];
            ++col[c];
            res[r][c] = '#';
            search(r, c+1);
            if (done) return;
            --row[r];
            --col[c];
            res[r][c] = '.';
        }
        search(r, c+1);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int x;
    cin >> x;
    n = 6;
    res.assign(n, string(n, '.'));
    row.assign(n, 0);
    col.assign(n, 0);
    done = false;
    search(0, 0);
    vs res6 = res;

    n = 6 + x%6;
    res.assign(n, string(n, '.'));
    row.assign(n, 0);
    col.assign(n, 0);
    done = false;
    search(0, 0);
    vs resn = res;
    for (string s : resn) cout << s << string(x-n, '.') << endl;
    for (int i=n; i+6<=x; i+=6) {
        for (string s : res6) cout << string(i, '.') << s << string(x-i-6, '.') << endl;
    }
}