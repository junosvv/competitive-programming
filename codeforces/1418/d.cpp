#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

template <class T> ostream& operator<<(ostream& os, set<T>& x) {
    os << '[';
    bool first = true;
    for (T i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

template <class T> ostream& operator<<(ostream& os, multiset<T>& x) {
    os << '[';
    bool first = true;
    for (T i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    set<lg> a;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    a.insert(-1e18);
    a.insert(1e18);

    multiset<lg> diffs;
    lg prv = -1;
    for (lg i : a) {
        if (prv != -1) diffs.insert(i - prv);
        prv = i;
    }

    auto getans = [&]() {
        if (a.size() <= 4) {
            cout << 0 << '\n';
            return;
        }
        cout << *prev(prev(a.end())) - *next(a.begin()) - *prev(prev(prev(diffs.end()))) << '\n';
    };

    getans();
    FOR(qi, 0, q) {
        int t;
        lg x;
        cin >> t >> x;

        if (t) {
            auto it = a.lower_bound(x);
            diffs.erase(diffs.find(*it - *prev(it)));
            diffs.insert(x - *prev(it));
            diffs.insert(*it - x);
            a.insert(x);
        } else {
            auto it = a.find(x);
            diffs.erase(diffs.find(*it - *prev(it)));
            diffs.erase(diffs.find(*next(it) - *it));
            diffs.insert(*next(it) - *prev(it));
            a.erase(it);
        }
        getans();
    }
}
