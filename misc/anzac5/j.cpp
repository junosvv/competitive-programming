#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define t4i tuple<int,int,int,int>
#define lg long long

int n;
vector<vi> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

bool flag = false;
vector<int> state;
void

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    while (true) {
        int R, C;
        cin >> R >> C;
        n = R*C;
        if (R == 0 && C == 0) break;

        vector<vector<vector<pii>>> wiresAt(R, vector<vector<pii>>(C));
        vector<pair<pii,pii>> wires(R*C);
        g.assign(n, {});
        gt.assign(n, {});
        FOR(i, 0, R*C) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            --r1; --c1; --r2; --c2;
            wires.emplace_back(pii{r1, c1}, pii{r2, c2});

            if (0<=r1&&r1<R && 0<=c1&&c1<C) wiresAt[r1][c1].emplace_back(i, 0);
            if (0<=r2&&r2<R && 0<=c2&&c2<C) wiresAt[r2][c2].emplace_back(i, 1);
        }

        FOR(r, 0, R) FOR(c, 0, C) {
            FOR(w1, 0, wiresAt[r][c].size()) FOR(w2, 0, wiresAt[r][c].size()) if (w1 != w2) {
                g[wiresAt[r][c][w1].first].push_back(wiresAt[r][c][w2].first);
            }
        }
        state.assign(R*C, {});
        dfs(0);
        if (flag) {
            
        }
    }
}