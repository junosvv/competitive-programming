#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>


ll X, Y, He, Me, Ht, Mt, d, h, m;

signed main() {
    cin >> X >> Y;
    cin >> He >> Me;
    cin >> Ht >> Mt;
    cin >> d >> h >> m;
    ll time_elased = 24 * 60 * d + 60 * h + m - (60 * He + Me);
    ll time_tatoo = time_elased + (Y * Ht + Mt);
    ll days = time_tatoo / (X * Y);

    time_tatoo = time_tatoo % (X * Y);
    ll hours = time_tatoo / Y;
    time_tatoo = time_tatoo % Y;
    ll mins = time_tatoo;

    cout << days << " " << hours << " " << mins << "\n";

}