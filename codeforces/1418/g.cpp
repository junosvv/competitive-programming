#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

int n;
vector<int> tree, occtree, lazy;
void inc(int x, int delta) {
    tree[x] += delta;
    if (x<n) lazy[x] += delta;
}

void merge(int x) {
    tree[x] = min(tree[2*x], tree[2*x+1]);
    occtree[x] = occtree[2*x] * (tree[x] == tree[2*x]) + occtree[2*x+1] * (tree[x] == tree[2*x+1]);
    tree[x] += lazy[x];
}

void fix(int x) {
    while (x) {
        merge(x);
        x /= 2;
    }
}

void upd(int l, int r, int delta) {
    if (r < 0 || r < l) return;
    if (l < 0) l = 0;
    l += n;
    r += n;
    int l0 = l;
    int r0 = r;
    while (l <= r) {
        if (l&1) inc(l++, delta);
        if (!(r&1)) inc(r--, delta);
        l /= 2;
        r /= 2;
    }
    fix(l0/2);
    fix(r0/2);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    vector<int> a(n);
    FOR(i, 0, n) cin >> a[i];
    
    tree.resize(2*n, 1);
    occtree.resize(2*n);
    FOR(i, n, 2*n) occtree[i] = 1;
    ROF(i, n-1, 0) occtree[i] = occtree[2*i] + occtree[2*i+1];
    lazy.resize(n);

    vector<vector<int>> occ(n+1, {-4, -3, -2, -1});

    lg res = 0;
    FOR(i, 0, n) {
        occ[a[i]].push_back(i);
        int s = occ[a[i]].size();
        upd(occ[a[i]][s-2]+1, occ[a[i]][s-1]-1, 1);
        upd(occ[a[i]][s-5]+1, occ[a[i]][s-4], 1);
        upd(occ[a[i]][s-4]+1, occ[a[i]][s-3], -1);
        if (tree[1] == 0) res += occtree[1];
    }
    cout << res << '\n';
}
