#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for (int i=0; i<(n); ++i)
#define IREP(i, n) for (int i=1; i<=(n); ++i)

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

const int BIGN = 200000;
int n;
map<pair<int,int>, int> edgeID;
vector<int> edges[BIGN];
int out[BIGN];
int maxcnt = -1;

void dfs(int x, int prev, int skip) {
    int cnt = 1;
    for (int y : edges[x]) {
        if (y != prev) {
            if (cnt == skip) ++cnt;
            out[edgeID[{min(x,y),max(x,y)}]] = cnt;
            maxcnt = max(maxcnt, cnt);
            dfs(y, x, cnt);
            ++cnt;
        }
    }
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    REP(i, n-1) {
        int a,b; cin >> a >> b;
        if (b<a) swap(a,b);
        edgeID[{a, b}] = i;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, 0, 0);
    cout << maxcnt << '\n';
    REP(i, n-1) cout << out[i] << '\n';
}