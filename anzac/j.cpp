#include <bits/stdc++.h>
using namespace std;

int ceil(int n, int d) {
    return n / d + (n % d != 0);
}
main() {
    ios::sync_with_stdio(0), cin.tie(0);
	
	int N, S; cin >> N >> S;
    int best = 0;
    for (int i = 0; i < N; ++i) {
        int ms; cin >> ms;
        ms *= S;
        best = max(best, ceil(ms, 1000));
    }
    cout << best << endl;
}