#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

vector<int> edges[200010];
bool seen[200010] = {};
int bigcomp[200010];
int n, m;

int dfs(int x) {
    if (seen[x]) return -1;
    seen[x] = true;
    int hi = x;
    for (int y : edges[x]) {
        int val = dfs(y);
        hi = max(hi, val);
    }
    return hi;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int end = -1, result = 0;
    for (int x=1; x<=n; ++x) {
        int hi = dfs(x);
        if (hi != -1) {
            if (x < end) ++result;
            end = max(end, hi);
        }
    }
    cout << result;
}