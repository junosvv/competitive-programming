#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for (int i=0; i<(n); ++i)
#define IREP(i, n) for (int i=1; i<(n); ++i)

#define popcount __builtin_popcountll

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}

template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

template <typename A>
string to_string(A x[], signed n) {
    string result = "{";
    for (signed i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

int n;
int arr[110], alt[110];

void thing(map<vector<int>,int> &inp) {
    REP(x, 1<<15) {
        vector<int> diff;
        int prev = popcount(x^alt[0]);
        IREP(i, n) {
            int cur = popcount(x^alt[i]);
            diff.push_back(cur-prev);
            prev = cur;
        }
        inp[diff] = x;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    REP(i, n) cin >> arr[i];

    map<vector<int>,int> tops, bottoms;

    REP(i, n) alt[i] = arr[i]&((1<<15)-1);
    thing(bottoms);
    REP(i, n) alt[i] = arr[i]>>15;
    thing(tops);

    bool failed = true;
    for (auto pr : bottoms) {
        vector<int> diff = pr.first;
        vector<int> altdiff;
        REP(i, n-1) altdiff.push_back(-diff[i]);
        if (tops.count(altdiff)) {
            failed = false;
            cout << (tops[altdiff]<<15) + bottoms[diff] << '\n';
            break;
        }
    }
    if (failed) cout << -1;
}
