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

char getThing(int x) {
	if (x <= 25) return x+'a';
	if (x <= 51) return (x-26)+'A';
	return (x-52)+'0';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int T; cin >> T;
	while (T--) {
		int R, C, N; cin >> R >> C >> N;
		string grid[R];
		int numRice = 0;
		for (int r=0; r<R; ++r) {
			cin >> grid[r];
			for (int c=0; c<C; ++c) if (grid[r][c] == 'R') ++numRice;
		}
		int n=0, result[R][C], count=0;
		int DIV = numRice/N;
		int BONUS = numRice%N;
		for (int r=0; r<R; ++r) {
			for (int c=(r%2==0?0:C-1); c!=(r%2==0?C:-1); c+=(r%2==0?1:-1)) {
				if (grid[r][c] == 'R') {
					if ((n<BONUS && count == DIV+1) || (n>=BONUS && count == DIV)) {
						++n;
						count = 0;
					}
					++count;
				}
				result[r][c] = n;
			}
		}
		for (int r=0; r<R; ++r) {
			for (int c=0; c<C; ++c) {
				cout << getThing(result[r][c]);
			}
			cout << "\n";
		}
	}
}