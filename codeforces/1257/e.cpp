#include <bits/stdc++.h>
using namespace std;
typedef long long lglg;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int a,b,c; cin >> a >> b >> c;
	int which[a+b+c+1];
	for (int i=0; i<a; ++i) {
		int x; cin >> x;
		which[x] = 1;
	}
	for (int i=0; i<b; ++i) {
		int x; cin >> x;
		which[x] = 2;
	}
	for (int i=0; i<c; ++i) {
		int x; cin >> x;
		which[x] = 3;
	}
	
	int prev[4] = {1, 1, 1, 1};
	prev[which[1]] = 0;
	for (int i=2; i<=a+b+c; ++i) {
		int cur[4] = {1, 1, 1, 1};
		cur[which[i]] = 0;

		cur[1] += prev[1];
		cur[2] += min(prev[1], prev[2]);
		cur[3] += min(prev[1], min(prev[2], prev[3]));

		for (int i=1; i<4; ++i) prev[i] = cur[i];
	}

	cout << min(prev[1], min(prev[2], prev[3]));
}