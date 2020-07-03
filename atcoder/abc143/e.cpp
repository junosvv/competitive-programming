#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;
const lglg INF = 1LL << 60;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N,M; lglg L; cin >> N >> M >> L;
	lglg adj[N+1][N+1], newadj[N+1][N+1];
	for (int i=1; i<=N; ++i) {
		for (int j=1; j<=N; ++j) {
			if (i==j) adj[i][j] = newadj[i][j] = 0;
			else adj[i][j] = newadj[i][j] = INF;
		}
	}
	for (int i=0; i<M; ++i) {
		int a,b,c; cin >> a >> b >> c;
		adj[a][b] = adj[b][a] = c;
	}

	for (int k=1; k<=N; ++k)
		for (int i=1; i<=N; ++i)
			for (int j=1; j<=N; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

	for (int i=1; i<=N; ++i)
		for (int j=1; j<=N; ++j)
			if (i != j && adj[i][j] <= L) newadj[i][j] = 1;

	for (int k=1; k<=N; ++k)
		for (int i=1; i<=N; ++i)
			for (int j=1; j<=N; ++j)
				newadj[i][j] = min(newadj[i][j], newadj[i][k]+newadj[k][j]);
	
	int T; cin >> T;
	while (T--) {
		int s, t; cin >> s >> t;
		if (newadj[s][t] == INF) cout << "-1\n";
		else cout << newadj[s][t]-1 << '\n';
	}
}