#include <bits/stdc++.h>
using namespace std;
 
typedef long long lglg;

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
string to_string(A x[], lglg n) {
    string result = "{";
    for (lglg i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

lglg check(string t) {
    lglg a=0,b;
    for (char c : t) if (c=='<') ++a;
    b = t.size()-a;
    if (b < a) swap(a,b);
    return (a-1)*a/2+b*(b+1)/2;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s; cin >> s;
    lglg n = s.size();
    
    string t; t += s[0];
    lglg result = 0;
    for (lglg i=1; i<n; ++i) {
        if (s[i-1] == '>' && s[i] == '<') {
            result += check(t);
            t.clear();
        }
        t += s[i];
    }
    result += check(t);
    cout << result;
}