#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

bool seen[3000] = {};
bool globalseen[3000] = {};
vector<int> edges[3000];
vector<int> cycle;

int dfs(int x) {
	if (seen[x]) return x;
	if (globalseen[x]) return -1;
	seen[x] = globalseen[x] = true;
	cycle.push_back(x);
	for (int y : edges[x]) {
		int val = dfs(y);
		if (val != -1) return val;
	}
	seen[x] = false;
	cycle.pop_back();
	return -1;
}

int main() {
    ios::sync_with_stdio(0);//, cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	for (int i=0; i<M; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
	}

	bool success = false;
	for (int x=1; x<=N; ++x) {
		int val = dfs(x);
		if (val != -1) {
			success = true;
			vector<int> newcycle;
			bool found = false;
			for (int i : cycle) {
				if (i == val) found = true;
				if (found) newcycle.push_back(i);
			}
			cycle = newcycle;
			while (true) {
				bool inCycle[N+1] = {};
				for (int i : cycle) inCycle[i] = true;
				int induced = -1;
				for (int i : cycle) {
					int adj = 0; for (int j : edges[i]) if (inCycle[j]) ++adj;
					if (adj >= 2) {
						induced = i;
						break;
					}
				}
				if (induced == -1) break;
				int nextind;
				for (int i=0; i<cycle.size(); ++i) {
					if (cycle[i] == induced) {
						nextind = cycle[(i+1)%cycle.size()];
						break;
					}
				}
				vector<int> newcycle;
				newcycle.push_back(induced);
				for (int j : edges[induced]) {
					if (inCycle[j] && j != nextind) {
						newcycle.push_back(j);
						break;
					}
				}
				int i=0;
				bool found = false;
				int lookingfor = newcycle.back();
				while (true) {
					if (cycle[i] == lookingfor) found = true;
					else if (found) {
						if (cycle[i] == induced) break;
						newcycle.push_back(cycle[i]);
					}
					++i;
					i %= cycle.size();
				}
				cycle = newcycle;
			}
			cout << cycle.size() << '\n';
			for (int i : cycle) cout << i << '\n';
			break;
		}
	}
	if (!success) cout << -1;
}