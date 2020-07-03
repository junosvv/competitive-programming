#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (__typeof(l) i = (l); i != (r); (l)<(r)?++i:--i)
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 998244353;

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

string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    for (signed i=d-1; i>=0; --i) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

int powa(int base, int exp) {
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp>>1);
    val = val*val % MOD;
    if (exp&1) {
        val = val*base % MOD;
    }
    return val;
}

const int BIGN = 1000010;
int s[BIGN<<1], sm[BIGN<<1], z[BIGN] = {};
int n;
 
void inc(int x, int amount) {
    s[x] += amount;
    sm[x] += amount;
    if (x < n) z[x] += amount;
}
 
void fix_parents(int x) {
    while (x >>= 1) {
        s[x]  = min(s[x<<1],s[x<<1|1]) + z[x];
        sm[x] = max(sm[x<<1],sm[x<<1|1]) + z[x];
    }
}
 
void upd(int l, int amount) {
    l += n;
    int oldL = l, r = (n<<1)-1, oldR = r;
    while (l <= r) {
        if (l&1) inc(l++, amount);
        if (!(r&1)) inc(r--, amount);
        l >>= 1;
        r >>= 1;
    }
    fix_parents(oldL);
    fix_parents(oldR);
}
 
int getval(char c) {
    return (c == '(') - (c == ')');
}
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    char x[n];
    REP(i, 0, n) {
        cin >> x[i];
    }
    int pos = 0;
    n = 0;
    for (char c : x) {
        if (c == 'R') ++pos;
        else if (c == 'L') --pos;
        pos = max(0LL, pos);
        n = max(n, pos);
    }
    ++n;
    char t[n]; REP(i, 0, n) t[i] = 'a';
    pos = 0;
    int balance = 0;
    for (char c : x) {
        if (c == 'L') --pos;
        else if (c == 'R') ++pos;
        else {
            int val = getval(c)-getval(t[pos]);
            if (val != 0) {
                balance += val;
                upd(pos, val);
            }
            t[pos] = c;
        }
        pos = max(0LL, pos);
        if (balance == 0 && s[1] >= 0) cout << sm[1] << ' ';
        else cout << "-1 ";
    } 
}