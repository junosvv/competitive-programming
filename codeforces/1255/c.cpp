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
string to_string(A x[], int n) {
    string result = "{";
    for (int i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> finder[n+1];
	tuple<int,int,int> triples[n-2];
	for (int i=0; i<n-2; ++i) {
		int a,b,c; cin >> a >> b >> c;
		triples[i] = {a, b, c};
		finder[a].push_back(i);
		finder[b].push_back(i);
		finder[c].push_back(i);
	}
	int start;
	for (int i=1; i<=n; ++i) {
		if (finder[i].size() == 1) {
			start = i;
			break;
		}
	}
	vector<int> result = {start};
	int a,b,c; tie(a,b,c) = triples[finder[start][0]];
	if (finder[a].size() == 2) {
		result.push_back(a);
		if (b == start) result.push_back(c);
		else result.push_back(b);
	} else if (finder[b].size() == 2) {
		result.push_back(b);
		if (a == start) result.push_back(c);
		else result.push_back(a);
	} else {
		result.push_back(c);
		if (a == start) result.push_back(b);
		else result.push_back(a);
	}
	bool proc[n-2] = {}, seen[n+1] = {};
	proc[finder[start][0]] = true;
	for (int i : result) seen[i] = true;
	while (result.size() < n) {
		int cur = result[result.size()-2];
		for (int id : finder[cur]) {
			if (!proc[id]) {
				int a,b,c; tie(a,b,c) = triples[id];
				if (!seen[a]) result.push_back(a);
				else if (!seen[b]) result.push_back(b);
				else result.push_back(c);
				seen[a] = seen[b] = seen[c] = true;
				proc[id] = true;
				break;
			}
		}
	}
	for (int i : result) cout << i << " ";
}