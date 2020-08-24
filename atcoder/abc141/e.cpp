#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

vector<int> getZ(int n, char s[]) {
	vector<int> z(n);
	int x = 0, y = 0;
	for (int i = 1; i < n; i++) {
		z[i] = max(0,min(z[i-x],y-i+1));
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
			x = i; y = i+z[i]; z[i]++;
		}
	}
	return z;
}


int main() {
    ios::sync_with_stdio(0);//, cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int k = 0;
	int bad = n/2 + 1;
	for (int b=n/2; b>=1; b/=2) {
		while (k+b < bad) {
			bool success = false;
			for (int l=0; l<n; ++l) {
				int r = l+k+b;
				if (r+k+b > n) break;
				char x[n-l+1];
				for (int i=l; i<r; ++i) x[i-l] = s[i];
				x[k+b] = '#';
				for (int i=r; i<n; ++i) x[i-l+1] = s[i];
				for (int i : getZ(n-l+1, x)) {
					if (i == k+b) {
						success = true;
						break;
					}
				}
				if (success) break;
			}
			if (!success) {
				bad = k+b;
				break;
			}
			k += b;
		}
	}
	cout << k;
}