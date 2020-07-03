#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int link[100010], mag[100010], prevs[100010], nexts[100010], first = 1, last = -1;
int find(int x) {
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (mag[y] < mag[x]) swap(x,y);
    link[x] = y;
    mag[y] += mag[x];
    if (x == first) first = nexts[x];
    else nexts[prevs[x]] = nexts[x];
    if (x == last) last = prevs[x];
    else prevs[nexts[x]] = prevs[x];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int V, E; cin >> V >> E;
    vector<int> edges[V+1];
    for (int i=0; i<E; ++i) {
        int a, b; cin >> a >> b;
        edges[max(a,b)].push_back(min(a,b));
    }

    for (int x=1; x<=V; ++x) {
        link[x] = x;
        mag[x] = 1;
        prevs[x] = last;
        if (last != -1) nexts[last] = x;
        nexts[x] = -1;
        last = x;

        map<int, int> conns;
        for (int y=first; nexts[y]!=-1; y=nexts[y]) conns[y] = 0;
        for (int y : edges[x]) ++conns[find(y)];
        for (auto pr : conns) {
            int y, num; tie(y, num) = pr;
            // cout << x << " conns to " << y << " with " << num << " against " << mag[y] << '\n';
            if (num < mag[y]) merge(x, y);
        }
    }

    int comps = 0;
    for (int x=1; x<=V; ++x) if (x == find(x)) ++comps;
    cout << comps-1;
}