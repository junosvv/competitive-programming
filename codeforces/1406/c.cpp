#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

long long MOD = 1e9+7;

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (auto i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

int n;
vector<int> subsz;
vector<vector<int>> nodes;
map<int, int> lrg;
int mn;
void dfs(int u, int p=-1) {
    int cmp = 0;
    for (int v : nodes[u]) if (v != p) {
        dfs(v, u);
        cmp = max(cmp, subsz[v]);
        subsz[u] += subsz[v];
    }
    cmp = max(cmp, n-subsz[u]);
    lrg[u] = cmp;
    mn = min(mn, cmp);
}

int leafdfs(int u, int p) {
    for (int v : nodes[u]) if (v != p) {
        return leafdfs(v, u);
    }
    return u;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        cin >> n;

        nodes.assign(n, {});
        FOR(i, 0, n-1) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }

        mn = 1e9;
        lrg.clear();
        subsz.assign(n, 1);
        dfs(0);

        vector<int> centroids;
        FOR(i, 0, n) {
            if (lrg[i] == mn) {
                centroids.push_back(i);
            }
        }

        if (centroids.size() == 1) {
            cout << 0+1 << ' ' << nodes[0][0] + 1 << '\n';
            cout << 0+1 << ' ' << nodes[0][0] + 1 << '\n';
        } else {
            int v = leafdfs(centroids[0], centroids[1]);
            cout << v+1 << ' ' << nodes[v][0] + 1 << '\n';
            cout << v+1 << ' ' << centroids[1] + 1 << '\n';
        }
    }
}