#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, k;
	string x;
	cin >> n >> k >> x;
	int comps = 1;
	for (int i=0; i<n-1; ++i) if (x[i] != x[i+1]) ++comps;
	cout << n - max(1, comps - 2*k);
}