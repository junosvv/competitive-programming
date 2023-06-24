#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vs strings(m);
    FOR(i, 0, m) cin >> strings[i];

    auto getstr = [&](int mask, int sz) {
        string res;
        FOR(d, 0, sz) {
            res.push_back('a'+(mask&1));
            mask >>= 1;
        };
        return res;
    };

    auto stringin = [&](string s, string t) {
        int n = s.size();
        int m = t.size();
        FOR(i, 0, m-n+1) {
            bool succ = true;
            FOR(j, 0, n) if (s[j] != t[i+j]) {
                succ = false;
                break;
            }
            if (succ) return true;
        }
        return false;
    };

    auto vibecheck = [&](string t) {
        for (string s : strings) if (stringin(s, t)) {
            return false;
        }
        return true;
    };

    auto getvec = [&](int n) {
        vi u(1<<n);
        FOR(mask, 0, 1<<n) {
            string t = getstr(mask, n);
            if (vibecheck(t)) {
                u[mask] = 1;
            }
        }
        return u;
    };

    auto matvec = [&](vvi mtrx, vi vec) {
        vi res(32);
        FOR(r, 0, 32) FOR(c, 0, 32) {
            res[r] = (res[r] + mtrx[r][c] * vec[c]) % MOD;
        }
        return res;
    };

    auto matmat = [&](vvi A, vvi B) {
        vvi res(32, vi(32));
        FOR(r, 0, 32) FOR(c, 0, 32) FOR(k, 0, 32) {
            res[r][c] = (res[r][c] + A[r][k] * B[k][c]) % MOD;
        }
        return res;
    };

    auto matpow = [&](vvi A, int k) {
        vvi res(32, vi(32));
        FOR(i, 0, 32) res[i][i] = 1;
        while (k) {
            if (k&1) res = matmat(res, A);
            A = matmat(A, A);
            k >>= 1;
        }
        return res;
    };

    vi u;
    if (n <= 5) {
        u = getvec(n);
    } else {
        u = getvec(5);
        vvi mtrx(32, vi(32));
        FOR(r, 0, 32) FOR(c, 0, 32) {
            string s = getstr(r, 5);
            string t = getstr(c, 5);
            bool succ = true;
            FOR(i, 0, 4) if (s[i] != t[i+1]) {
                succ = false;
                break;
            }
            if (succ && vibecheck(t + s.back())) {
                mtrx[r][c] = 1;
            }
        }

        mtrx = matpow(mtrx, n-5);
        u = matvec(mtrx, u);
    }
    cout << accumulate(u.begin(), u.end(), 0LL) % MOD << '\n';
}