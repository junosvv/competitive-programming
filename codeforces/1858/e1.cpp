#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int q;
    cin >> q;
    vi stack = {0};
    vi value = {0};
    vvi questions(1);
    int qcnt = 0;
    const int K = 21;
    vvi up(1, vi(K));
    vvi G(1);

    FOR(qi, 0, q) {
        char c;
        cin >> c;
        if (c == '+') {
            int nt = value.size();
            G[stack.back()].push_back(nt);
            up.push_back(vi(K));
            up.back()[0] = stack.back();
            FOR(k, 1, K) up.back()[k] = up[up.back()[k-1]][k-1];
            stack.push_back(nt);
            G.emplace_back();
            questions.emplace_back();
            value.push_back(0);
            cin >> value.back();
        }
        if (c == '-') {
            int x;
            cin >> x;
            stack.push_back(stack.back());
            FOR(k, 0, K) if (x>>k&1) stack.back() = up[stack.back()][k];
        }
        if (c == '?') {
            questions[stack.back()].push_back(qcnt++);
        }
        if (c == '!') {
            stack.pop_back();
        }
    }

    const int BIG = 1e6 + 1;
    vi cnt(BIG);
    vi tree(2*BIG);

    auto updtree = [&](int x, int val) {
        x += BIG;
        tree[x] += val;
        x /= 2;
        while (x) {
            tree[x] += val;
            x /= 2;
        }
    };

    auto upd = [&](int x, int val) {
        if (cnt[x] == 0) updtree(x, val);
        cnt[x] += val;
        if (cnt[x] == 0) updtree(x, val);
    };

    vi res(qcnt);
    function<void(int)> dfs = [&](int u) {
        for (int i : questions[u]) res[i] = tree[1];
        for (int v : G[u]) {
            upd(value[v], 1);
            dfs(v);
            upd(value[v], -1);
        }
    };
    dfs(0);
    for (int i : res) cout << i << ' ';
}