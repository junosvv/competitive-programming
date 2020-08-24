#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

vector<int> perm;
bool chosen[8] = {};
int n;
lglg adj[8][8];
long double result = 0;
void search() {
	if (perm.size() == n) {
		int prev = perm[0];
		for (int i=1; i<n; ++i) {
			result += sqrt(adj[prev][perm[i]]);
			prev = perm[i];
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			perm.push_back(i);
			search();
			chosen[i] = false;
			perm.pop_back();
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);

	cin >> n;
	int x[n], y[n];
	for (int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			adj[i][j] = (lglg)(x[i]-x[j])*(x[i]-x[j]) + (lglg)(y[i]-y[j])*(y[i]-y[j]);
			adj[j][i] = (lglg)(x[i]-x[j])*(x[i]-x[j]) + (lglg)(y[i]-y[j])*(y[i]-y[j]);
		}
	}

	search();
	for (int i=2; i<=n; ++i) result /= i;
	cout << setprecision(12) << result;
}