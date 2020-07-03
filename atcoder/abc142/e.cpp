#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int N, M, costs[1012];
vector<int> unlocks[1012];
int dp[1<<12];

void prnt(int x) {
	for (int i=11; i>=0; --i) {
		if (x&(1<<i)) cout << 1;
		else cout << 0;
	}
	cout << endl;
}

int solve(int x) {
	if (dp[x] != -1) return dp[x];
	int best = -1;
	for (int k=0; k<M; ++k) {
		int cost = costs[k];
		int newx = x;
		for (int u : unlocks[k]) {
			newx &= ~(1<<u);
		}
		if (x == newx) continue;
		cost += solve(newx);
		if (best == -1 || cost < best) best = cost;
	}
	dp[x] = best;
	return best;
}

int main() {
    ios::sync_with_stdio(0);//, cin.tie(0), cout.tie(0);

	cin >> N >> M;
	int boxes = 0;
	for (int i=0; i<M; ++i) {
		int a, b; cin >> a >> b;
		costs[i] = a;
		for (int j=0; j<b; ++j) {
			int c; cin >> c;
			unlocks[i].push_back(c-1);
			boxes |= 1 << (c-1);
		}
	}
	if (boxes != (1<<N)-1) cout << -1;
	else {
		for (int i=0; i<(1<<12); ++i) dp[i] = -1;
		dp[0] = 0;
		cout << solve((1<<N)-1);
	}
}