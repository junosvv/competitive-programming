#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string s; lglg r; cin >> s >> r;
	lglg n = s.size();
	lglg index = 1;
	while (index < n && s[index-1] == s[index]) ++index;
	if (index == n) cout << n*r/2;
	else {
		string loop, suffix;
		for (lglg i=index; i<n+index; ++i) loop += s[i%n];
		for (lglg i=index; i<n; ++i) suffix += s[i%n];
		lglg result = 0;
		lglg count = 1;
		for (lglg i=1; i<n; ++i) {
			if (loop[i-1] == loop[i]) ++count;
			else {
				result += count/2;
				count = 1;
			}
		}
		result += count/2;
		count = 1;
		result *= r-1;
		result += index/2;
		for (lglg i=1; i<n-index; ++i) {
			if (suffix[i-1] == suffix[i]) ++count;
			else {
				result += count/2;
				count = 1;
			}
		}
		result += count/2;
		cout << result;
	}
}