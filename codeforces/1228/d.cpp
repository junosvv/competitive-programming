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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> edges[n+1];
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    map<set<int>,vector<int>> thing;

    IREP(i, n+1) {
        thing[edges[i]].push_back(i);
    }
    
    if (thing.size() != 3) cout << -1;
    else {
        int comp = 1;
        bool failed = false;
        int res[n+1];
        for (auto pr : thing) {
            set<int> neighbours;
            vector<int> inComp;
            tie(neighbours, inComp) = pr;
            if (neighbours.size() + inComp.size() != n) {
                failed = true;
                break;
            }
            for (int i : inComp) res[i] = comp;
            ++comp;
        }
        if (failed) cout << -1;
        else {
            IREP(i, n+1) cout << res[i] << " ";
        }
    }
}
