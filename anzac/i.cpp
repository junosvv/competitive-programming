#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)

namespace output {
    void pr(short x) { cout << x; }
    void pr(signed x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(long long x) { cout << x; }
    void pr(unsigned short x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(long double x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { cout << x; }
    template<size_t sz> void pr(const bitset<sz>& x) { cout << x; }
    template<class T> void pr(const complex<T>& x) { cout << x; }
    
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T1, class T2, class T3> void pr(const tuple<T1,T2,T3>& x);
    template<class T> void pr(const T& x);
    
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { pr("(",x.first,", ",x.second,")"); }
    template<class T1, class T2, class T3> void pr(const tuple<T1,T2,T3>& x) { pr("(",get<0>(x),", ",get<1>(x),", ",get<2>(x),")"); }
    template<class T> void pr(const T& x) { 
        pr("["); // const iterator needed for vector<bool>
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
        pr("]");
    }
    
    void print() { pr("\n"); } // print w/ spaces
    template<class T, class... Ts> void print(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); print(ts...); }
}
using namespace output;
 
#define vi vector<int>
#define vvi vector<vi>

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int R, C;
    cin >> R >> C;

    vvi grid(R, vi(C));
    FOR(r, 0, R) FOR(c, 0, C) cin >> grid[r][c];

    vvi res(R, vi(C));

    FOR(r, 1, R-1) FOR(c, 1, C-1) {
        bool failed = false;
        for (auto delta : vector<pair<int,int>>{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}) {
            int rr = r + delta.first;
            int cc = c + delta.second;
            if (grid[rr][cc] <= grid[r][c]) failed = true;
        }
        res[r][c] = !failed;
    }

    FOR(r, 0, R) {
        FOR(c, 0, C) {
            cout << res[r][c] << ' ';
        }
        cout << '\n';
    }
}