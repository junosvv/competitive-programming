#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for (int i=0; i<(n); ++i)
#define IREP(i, n) for (int i=1; i<=(n); ++i)
#define popcount __builtin_popcountll

const int INF = 1LL<<60;

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

int n, k;
string x;
vector<int> opsA, opsB;

void make(char brac, int pos) {
    int i=pos;
    while (x[i] != brac) ++i;
    if (i == pos) return;
    opsA.push_back(pos);
    opsB.push_back(i);
    x[pos] = brac;
    x[i] = (brac=='('?')':'(');
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        opsA.clear();
        opsB.clear();
        REP(i, k-1) {
            make('(', 2*i+0);
            make(')', 2*i+1);
        }
        int rem = n/2-k+1;
        REP(i, rem) make('(', 2*(k-1)+i);
        REP(i, rem) make(')', 2*(k-1)+rem+i);
        cout << opsA.size() << '\n';
        REP(i, opsA.size()) cout << opsA[i]+1 << " " << opsB[i]+1 << '\n';
    }
}