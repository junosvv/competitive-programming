#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

void maxi(int& a, int b) {
    a = max(a, b);
}
void mini(int& a, int b) {
    a = min(a, b);
}

struct Block {
    int w, s, v;
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<Block> blocks(n);
    FOR(i, 0, n) cin >> blocks[i].w >> blocks[i].s >> blocks[i].v;
    sort(blocks.begin(), blocks.end(), [](Block& a, Block& b) {
        return a.w + a.s < b.w + b.s;
    });

    const int BIG = 2e4+1, INF = 1e15;
    vi dp(BIG, -INF);
    dp[0] = 0;
    FOR(i, 0, n) {
        Block& a = blocks[i];
        vi dp2 = dp;
        FOR(w, a.w, min(BIG, a.w + a.s + 1)) if (dp[w - a.w] != -INF) {
            maxi(dp2[w], a.v + dp[w - a.w]);
        }
        dp = dp2;
    }
    cout << *max_element(dp.begin(), dp.end());
}