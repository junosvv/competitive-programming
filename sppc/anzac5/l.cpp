#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vector<vi> adj;
vector<vi> cap;

int bfs(int s, int t, vector<int>& parent) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, 1e9});
	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		for (int next : adj[cur]) {
			if (parent[next] == -1 && cap[cur][next]) {
				parent[next] = cur;
				int new_flow = min(flow, cap[cur][next]);
				if (next == t) return new_flow;
				q.push({next, new_flow});
			}
		}
	}
	return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
	vector<int> parent (t+1);
	int new_flow;
	while (true) {
		new_flow = bfs(s, t, parent);
		if (new_flow == 0) break;
		flow += new_flow;
		int cur = t;
		while (cur != s) {
			int prev = parent[cur];
			cap[prev][cur] -= new_flow;
			cap[cur][prev] += new_flow;
			cur = prev;
		}
	}
	return flow;
}

int N;

void solve() {
	vector<vector<int>> capo = vector<vector<int>> (N, vector<int> (N));
	vector<vector<int>> adjo = vector<vector<int>> (N);

	string whyisthisneeded;
	getline(cin, whyisthisneeded);

	for (int i = 0; i < N; ++i) {
		string s;
		getline(cin, s);
		istringstream iss(s);
		vector<int> ints;
		int x;
		while (iss >> x) {
			ints.push_back(x);
		}
		for (int j : ints) {
			capo[i][j] = 1;
			adjo[i].push_back(j);
		}
	}
	
	int best = 0;
	for (int s = 0; s < N; ++s) for (int t = 0; t < N; ++t) {
		cap = capo;
		adj = adjo;

		int flow = maxflow(s, t);
		best = max(best, flow);
	}
	cout << best << endl;
}
int main() {
	while (true) {
		cin >> N;
		if (N != 0) solve();
		else break;
	}
}