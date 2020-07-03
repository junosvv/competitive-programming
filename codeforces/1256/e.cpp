#include <bits/stdc++.h>
using namespace std;

// nice things
typedef long long lglg;
#define len(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    pair<lglg,int> a[n];
    for (int i=0; i<n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    pair<lglg, int> dp[n];
    for (int i=2; i<min(5, n); ++i) dp[i] = {a[i].first - a[0].first, 0};

    for (int i=5; i<n; ++i) {
        dp[i] = {-1, 0};
        for (int lg=3; lg<=5; ++lg) {
            if (i-lg < 2) continue;
            lglg val = dp[i-lg].first + a[i].first - a[i-lg+1].first;
            if (dp[i].first == -1 || val < dp[i].first) dp[i] = {val, lg};
        }
    }

    int teams[n], teamCount = 1, i = n-1;
    while (i >= 5) {
        for (int j=i; j>i-dp[i].second; --j) {
            teams[a[j].second] = teamCount;
        }
        i -= dp[i].second;
        ++teamCount;
    }
    for (int j=i; j>=0; --j) {
        teams[a[j].second] = teamCount;
    }
    cout << dp[n-1].first << " " << teamCount << '\n';
    for (int i=0; i<n; ++i) cout << teams[i] << " ";
}