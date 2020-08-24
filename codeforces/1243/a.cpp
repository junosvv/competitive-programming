#include <bits/stdc++.h>
using namespace std;

// nice things
typedef long long lglg;
#define len(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int a[N]; for (int i=0; i<N; ++i) cin >> a[i];
        sort(a, a+N, greater<int>());
        int i=1;
        while (i < N && a[i] >= i+1) ++i;
        cout << i << '\n';
    }
}