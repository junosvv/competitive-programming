
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

void rt(string &s, int i) {
    if (s[i] == 'F') {
        s[i] = 'A';
        return;
    }
    ++s[i];
}

const vi trans = {4, 0, 5, 1, 6, 2, 7, 3};
void apply(int i, string &cur) {
    int x = cur[i]-'A';
    if (x == 0) {
        if (i != 0) rt(cur, i-1);
        if (i != 7) rt(cur, i+1);
    } else if (x == 1) {
        if (i != 0 && i != 7) {
            cur[i+1] = cur[i-1];
        }
    } else if (x == 2) {
        rt(cur, 7-i);
    } else if (x == 3) {
        if (i <= 3) {
            FOR(j, 0, i) rt(cur, j);
        } else {
            FOR(j, i+1, 8) rt(cur, j);
        }
    } else if (x == 4) {
        if (i != 0 && i != 7) {
            int ce, alt;
            if (i <= 3) {
                ce = 0;
                alt = i+i;
            } else {
                ce = 7;
                alt = i-(ce-i);
            }
            rt(cur, ce);
            rt(cur, alt);
        }
    } else if (x == 5) {
        rt(cur, trans[i]);
    }
}

int conv(string &a) {
    int res = 0;
    int tk = 1;
    FOR(i, 0, 8) {
        res += (a[i]-'A')*tk;
        tk *= 6;
    }
    // print("conv", a, ":", res);
    return res;
}

// #include <chrono>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string start, goal;
    cin >> start >> goal;

    // char start[8], goal[8];
    // FOR(i, 0, 8) cin >> start[i];
    // FOR(i, 0, 8) cin >> goal[i];
    
    // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // bool eq = true;
    // FOR(i, 0, 8) if (start[i] != goal[i]) eq = false;

    // if (eq) {
    //     cout << 0 << '\n';
    //     exit(0);
    // }

    if (start == goal) {
        cout << 0 << '\n';
        exit(0);
    }

    vector<string> q;
    // char q[1679620][8];
    // FOR(i, 0, 1679620) q[i][0] = 'z';
    // FOR(i, 0, 8) q[0][i] = start[i];
    q.push_back(start);

    int qi = 0;
    // int upto = 1;

    // unordered_map<string, int> dist;
    vi dist2(1679620, -1);

    // vi dist(1679620, -1);
    // dist[conv(start)] = 0;
    // dist[start] = 0;
    dist2[conv(start)] = 0;

    while (qi < (int)q.size()) {
        string cur = q[qi++];

        // int dst = dist[cur];
        int dst2 = dist2[conv(cur)];
        // int dst = dist[conv(cur)];
        FOR(i, 0, 8) {
            string nxt = cur;
            apply(i, nxt);
            int t = conv(nxt);
            if (dist2[t] == -1) {
            // if (!dist.count(nxt)) {
                // dist[nxt] = dst + 1;
                dist2[t] = dst2 + 1;
                q.push_back(nxt);
            }
        }
    }
    cout << dist2[conv(goal)] << '\n';

    // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}