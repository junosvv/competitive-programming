#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, const vector<T>& x) {
    os << '[';
    bool first = true;
    for (const T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

int mex(int a, int b) {
    FOR(res, 0, 3) {
        if (res != a && res != b) return res;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    vi cnt(3);
    
    int n;
    cin >> n;
    
    const int M = min(n, 3LL);
    vector<vi> gridr(M, vi(n)), gridc(n, vi(M));
    FOR(c, 0, n) {
        cin >> gridr[0][c];
        if (c < M) gridc[0][c] = gridr[0][c];
        ++cnt[gridr[0][c]];
    }
    FOR(r, 1, n) {
        cin >> gridc[r][0];
        if (r < M) gridr[r][0] = gridc[r][0];
        ++cnt[gridc[r][0]];
    }
    FOR(r, 1, n) FOR(c, 1, n) {
        if (r >= M && c >= M) break;
        if (r < M) {
            gridr[r][c] = mex(gridr[r-1][c], gridr[r][c-1]);
            if (c < M) gridc[r][c] = gridr[r][c];
            ++cnt[gridr[r][c]];
        } else {
            gridc[r][c] = mex(gridc[r-1][c], gridc[r][c-1]);
            ++cnt[gridc[r][c]];
        }
    }
    
    FOR(c, M-1, n) {
        cnt[gridr[M-1][c]] += n-1-c;
    }
    FOR(r, M, n) {
        cnt[gridc[r][M-1]] += n-1-r;
    }

    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
}
