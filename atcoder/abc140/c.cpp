#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	int arr[n+1];
	arr[0] = arr[n] = 1 << 30;
	for (int i=1; i<n; ++i) cin >> arr[i];
	int result = 0;
	for (int i=0; i<n; ++i) result += min(arr[i], arr[i+1]);
	cout << result;
}