#include <bits/stdc++.h>
using namespace std;

// nice things
typedef long long lglg;
#define len(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    lglg N, M; cin >> N >> M;
    priority_queue<lglg> q;
    for (lglg i=0; i<N; ++i) {
        lglg x; cin >> x;
        q.push(x);
    }
    for (lglg i=0; i<M; ++i) {
        lglg a = q.top();
        q.pop();
        q.push(a/2);
    }
    lglg result = 0;
    while (!q.empty()) {
        result += q.top();
        q.pop();
    }
    cout << result;
}