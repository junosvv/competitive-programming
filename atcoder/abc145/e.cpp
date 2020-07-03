#include <bits/stdc++.h>
using namespace std;
 
typedef long long lglg;
 
int N, T;
pair<int, int> dishes[3012];
int dp[3012][3012][2];
int search(int n, int t, int flag) {
    if (n == 0) return 0;
    if (t == 0) {
        if (flag == 0) return 0;
        return dishes[n-1].first;
    }
    if (dp[n][t][flag] != -1) return dp[n][t][flag];
    int val;
    int notinc = search(n-1, t, 0) + (flag ? dishes[n-1].first : 0);
    if (dishes[n-1].second > t) val = notinc;
    else val = max(notinc, dishes[n-1].first + search(n-1, t-dishes[n-1].second, flag));
    dp[n][t][flag] = val;
    return val;
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    for (int i=0; i<3012; ++i) dishes[i] = {4000, 4000};
    for (int i=0; i<3012; ++i) for (int j=0; j<3012; ++j) for (int k=0; k<2; ++k) dp[i][j][k] = -1;

    cin >> N >> T;
    for (int i=0; i<N; ++i) {
        int a, b; cin >> a >> b;
        dishes[i] = {b, a};
    }

    sort(dishes, dishes+3012);

    int val = search(N, T-1, 1);
    cout << val;
}