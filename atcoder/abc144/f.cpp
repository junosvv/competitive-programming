#include <bits/stdc++.h>
using namespace std;
typedef long long lglg;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	vector<int> edges[N];
	for (int i=0; i<M; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
	}

	bool bad[N];
	for (int i=1; i<N; ++i) bad[i] = (edges[i].size() <= 1);
	double dp[N+1][N];
	for (int i=0; i<N; ++i) dp[N][i] = 0;

	for (int x=N-1; x>=1; --x) {
		double result = 0, worst = -1;
		for (int y : edges[x]) {
			result += dp[y][0];
			if (dp[y][0] > worst) worst = dp[y][0];
		}
		double newresult = result/edges[x].size() + 1;
		for (int i=0; i<x; ++i) dp[x][i] = newresult;
		if (bad[x]) dp[x][x] = -1;
		else dp[x][x] = (result-worst)/(edges[x].size()-1) + 1;
		for (int i=x+1; i<N; ++i) {
			if (bad[i]) {
				dp[x][i] = -1;
				continue;
			}
			double result = 0;
			for (int y : edges[x]) result += dp[y][i];
			dp[x][i] = result/edges[x].size() + 1;
		}
	}
	
	double best = -1;
	for (int i=0; i<N; ++i) {
		if (dp[1][i] != -1 && (best == -1 || dp[1][i] < best)) best = dp[1][i];
	}
	cout << setprecision(12) << best;
}