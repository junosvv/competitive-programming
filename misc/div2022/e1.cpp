#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define t3i tuple<int,int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    
    vi l(n), r(n);
    vector<t3i> tups;
    FOR(i, 0, n) {
        cin >> l[i] >> r[i];
        --l[i]; --r[i];
        tups.emplace_back(l[i], r[i], i);
    }
    sort(tups.begin(), tups.end());
    reverse(tups.begin(), tups.end());

    vi tree(2*n);
    auto query = [&](int l, int r) {
        l += n;
        r += n;
        int res = 0;
        while (l <= r) {
            if (l&1) res = max(res, tree[l++]);
            if (!(r&1)) res = max(res, tree[r--]);
            l /= 2;
            r /= 2; 
        }
        return res;
    };

    auto upd = [&](int x, int delta) {
        x += n;
        tree[x] = delta;
        x /= 2;
        while (x) {
            tree[x] = max(tree[2*x], tree[2*x+1]);
            x /= 2;
        }
    };

    FOR(left, 0, r[0]+1) {
        while (!tups.empty()) {
            int li, ri, i;
            tie(li, ri, i) = tups.back();
            if (li > left) break;
            upd(i, ri);
            tups.pop_back();
        }

        int right = r[left] + 1;
        int upp = left==0 ? n : r[left-1] + 1;
        while (right < upp) {
            int q = query(left, right);
            if (q < right) {
                cout << "No " << left+1 << ' ' << right+1;
                exit(0);
            }
            right = q + 1;
        }
    }

    cout << "Yes";
}