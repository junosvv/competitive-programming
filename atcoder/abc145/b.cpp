#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);

	int n; string s;
	cin >> n >> s;

	if (n%2==1) cout << "No";
	else {
		bool success = true;
		for (int i=0;i<n/2; ++i) {
			if (s[i] != s[i+n/2]) {
				success = false;
				break;
			}
		}
		if (success) cout << "Yes";
		else cout << "No";
	}
}