#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];

	set<int> in;
	set<int> out;
	int employ = 0;

	bool valid = true;
	int last = -1;
	vector<int> result;
	for (int i=0; i<n; ++i) {
		if (a[i] > 0) {
			if (in.count(a[i]) || out.count(a[i])) {
				valid = false;
				break;
			}
			in.insert(a[i]);
			++employ;
		} else {
			if (!in.count(-a[i])) {
				valid = false;
				break;
			}
			in.erase(-a[i]);
			out.insert(-a[i]);
			--employ;
		}
		if (employ == 0) {
			result.push_back(i-last);
			in.clear();
			out.clear();
			last = i;
		}
	}
	if (valid && employ == 0) {
		cout << result.size() << '\n';
		for (int i : result) cout << i << ' ';
	} else cout << -1;
}