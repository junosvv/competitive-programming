#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;
const int INF = 1 << 28;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	int adj[n][n];
	vector<pair<int,int>> edges;
	for (int i=0; i<n; ++i) {
		string x; cin >> x;
		for (int j=0; j<n; ++j) {
			if (i == j) adj[i][j] = 0;
			else if (x[j] == '1') {
				adj[i][j] = 1;
				if (i < j) edges.push_back({i, j});
			}
			else adj[i][j] = INF;
		}
	}

	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	
	bool failed = false;
	for (pair<int,int> pr : edges) {
		int x, y; tie(x, y) = pr;
		if (adj[0][x] == adj[0][y]) {
			failed = true;
			break;
		}
	}
	if (failed) cout << -1;
	else {
		int best = -1;
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) best = max(best, adj[i][j]);
		cout << best+1;
	}
}