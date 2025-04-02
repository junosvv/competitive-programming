#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, F;
    cin >> n >> F;

    vvi capac(n, vi(n)), flow(n, vi(n));
    FOR(i, 0, n) FOR(j, 0, n) {
        cin >> capac[i][j];
    }
    vi height(n), excess(n);
    height[0] = n;
    excess[0] = 1e18;

    auto push = [&](int u, int v) {
        int d = min(excess[u], capac[u][v] - flow[u][v]);
        flow[u][v] += d;
        flow[v][u] -= d;
        excess[u] -= d;
        excess[v] += d;
    };

    auto relabel = [&](int u) {
        int d = 1e18;
        FOR(i, 0, n) {
            if (capac[u][i] - flow[u][i] > 0) {
                d = min(d, height[i]);
            }
        }
        if (d < 1e18) {
            height[u] = d + 1;
        }
    };

    auto find_max_height_vertices = [&]() {
        vi max_height;
        FOR(i, 1, n-1) if (excess[i] > 0) {
            if (!max_height.empty() && height[i] > height[max_height[0]]) max_height.clear();
            if (max_height.empty() || height[i] == height[max_height[0]]) max_height.push_back(i);
        }
        return max_height;
    };

    FOR(i, 1, n) {
        push(0, i);
    }

    vi current;
    while (!(current = find_max_height_vertices()).empty()) {
        for (int i : current) {
            bool pushed = false;
            for (int j=0; j<n && excess[i]; ++j) {
                if (capac[i][j] - flow[i][j] > 0 && height[i] == height[j] + 1) {
                    push(i, j);
                    pushed = true;
                }
            }
            if (!pushed) {
                relabel(i);
                break;
            }
        }
    }

    queue<int> q;
    q.push(0);
    vi seen(n);
    seen[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        FOR(v, 0, n) if (capac[u][v] - flow[u][v] > 0 && !seen[v]) {
            seen[v] = true;
            q.push(v);
        }
    }

    int mf = excess[n-1];
    if (mf > F) {
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                if (capac[i][j] && seen[i] && !seen[j]) {
                    int cur = min(mf - F, capac[i][j]);
                    capac[i][j] -= cur;
                    mf -= cur;
                }
            }
        }
    }
    
    FOR(i, 0, n) {
        FOR(j, 0, n) cout << capac[i][j] << ' ';
        cout << '\n';
    }
}