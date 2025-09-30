#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>

long long INF = 1LL<<60;
long long MOD = 1e9+7;

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

main() {
    ios::sync_with_stdio(0), cin.tie(0);
	
	int N, S; cin >> N >> S;
    vector<vi> grid (N, vi (N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c; cin >> c;
            if (c == 'D') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    vector<vi> cumsum (N+1, vi (N+1));
    for (int i = 0; i < N; ++i) {
        cumsum[0][i] = 0;
        cumsum[i][0] = 0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cumsum[i+1][j+1] = cumsum[i+1][j] + cumsum[i][j+1] - cumsum[i][j] + grid[i][j];
        }
    }

    map<int, int> occ;
    int ans = 0;
    for (int i = 0; i + S <= N; ++i) {
        for (int j = 0; j + S <= N; ++j) {
            occ[cumsum[i+S][j+S] - cumsum[i][j+S] - cumsum[i+S][j] + cumsum[i][j]]++;
        }
    }
    for (int i = 0; i <= S * S; ++i) {
        if (occ[i] != 0) {
            cout << i << " " << occ[i] << endl;
        }
    }
}