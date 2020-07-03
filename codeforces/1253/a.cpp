#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int a[n], b[n], x[n];
		for (int i=0; i<n; ++i) cin >> a[i];
		for (int i=0; i<n; ++i) cin >> b[i];

		for (int i=0; i<n; ++i) x[i] = a[i] - b[i];
		int state = 0;
		int val;
		bool failed = false;
		for (int i=0; i<n; ++i) {
			if (x[i] > 0) {
				failed = true;
				break;
			}
			if (state == 0 && x[i] != 0) {
				state = 1;
				val = x[i];
			} else if (state == 1) {
				if (x[i] == 0) {
					state = 2;
				} else if (x[i] != val) {
					failed = true;
					break;
				}
			} else if (state == 2) {
				if (x[i] != 0) {
					failed = true;
					break;
				}
			}
		}
		if (failed) cout << "NO\n";
		else cout << "YES\n";
	}
}