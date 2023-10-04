#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vvs vector<vs>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int cnt = 0;
    vvs piece(3, vs(4, string(4, ' ')));
    FOR(i, 0, 3) FOR(r, 0, 4) {
        cin >> piece[i][r];
        for (int c : piece[i][r]) if (c == '#') ++cnt;
    }
    if (cnt != 16) {
        cout << "No";
        exit(0);
    }

    auto rotate = [&](vs& a) {
        vs b(4, string(4, ' '));
        FOR(r, 0, 4) FOR(c, 0, 4) b[r][c] = a[c][3-r];
        swap(a, b);
    };
    
    auto update = [&](vs& res, int upto, int r, int c) {
        FOR(dr, 0, 4) FOR(dc, 0, 4) if (piece[upto][dr][dc] == '#') {
            if (!(0 <= r+dr && r+dr < 4 && 0 <= c+dc && c+dc < 4 && res[r+dr][c+dc] != '#')) return false;
            res[r+dr][c+dc] = '#';
        }
        return true;
    };
    
    function<void(vs&,int)> solve = [&](vs& res, int upto) {
        if (upto == 3) {
            cout << "Yes";
            exit(0);
        }
        FOR(r, -3, 4) FOR(c, -3, 4) {
            vs res0 = res;
            if (update(res, upto, r, c)) {
                solve(res, upto+1);
            }
            res = res0;
        }
    };


    FOR(_, 0, 4) {
        FOR(_, 0, 4) {
            vs res(4, string(4, '.'));
            solve(res, 0);
            rotate(piece[2]);
        }
        rotate(piece[1]);
    }
    cout << "No";
}