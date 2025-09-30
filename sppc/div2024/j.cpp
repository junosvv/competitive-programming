#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vector<pii> points(n);
    FOR(i, 0, n) cin >> points[i].first >> points[i].second;
    sort(points.begin(), points.end());

    auto cross = [&](pii a, pii b, pii c) {
        // AB x AC
        return (b.first-a.first)*(c.second-a.second) - (b.second-a.second)*(c.first-a.first);
    };

    vector<pii> lower = {points[0]};
    for (pii pt : points) {
        while (lower.size() >= 2 && cross(lower[lower.size()-2], lower.back(), pt) <= 0) lower.pop_back();
        lower.push_back(pt);
    }
    lower.pop_back();
    reverse(points.begin(), points.end());
    vector<pii> upper = {points[0]};
    for (pii pt : points) {
        while (upper.size() >= 2 && cross(upper[upper.size()-2], upper.back(), pt) <= 0) upper.pop_back();
        upper.push_back(pt);
    }
    upper.pop_back();
    for (pii pt : upper) lower.push_back(pt);

    cout << "hull:\n";
    for (pii pt : lower) {
        cout << pt.first << ' ' << pt.second << '\n';
    }
    cout << '\n';

    int j=2;
    FOR(i, 0, lower.size()) {
        
    }
}