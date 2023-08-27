#include <bits/stdc++.h>
using namespace std;

int main() {
    int green, red;
    int startQueue, starttime;
    deque<pair<int, int>> index;
    cin >> green >> red;
    cin >> startQueue >> starttime;
    index.push_back({startQueue, starttime});
    int maxTime = 0;
    int maxQueue = startQueue;
    int n;
    cin >> n;
    int i = 0;
    while (n--) {
        char light;
        int nCars;
        cin >> light >> nCars;
        if (light == 'G') {
            startQueue -= nCars;
            int j = 0;
            for (pair<int, int>& entry: index) {
                if (entry.first <= 0) continue;
                entry.first -= nCars;
                // If the car has left
                if (entry.first <= 0) {
                    maxTime = max(entry.second, maxTime);

                } else {
                    entry.second += green;
                }
            }
        } else {
            startQueue += nCars;
            maxQueue = max(maxQueue, startQueue);
            // Check if:
            // start time at red or 0
            // if I should use startqueue or startqueue - 1
            pair<int, int> entry = {startQueue, 0};
            index.push_back(entry);
            for (auto& entry: index) {
                if (entry.first <= 0) continue;
                entry.second += red;
            }
        }
        //cout << i << "\n";
        for (auto entry : index) {
            //cout << entry.first << " time: " << entry.second  << "\n";
        }
        i++;
    }
    string vehicles = (maxQueue == 1) ? " vehicle.\n" : " vehicles.\n";
    cout << "Longest queue was " << maxQueue << vehicles;
    int minutes = maxTime / 60;
    int seconds = maxTime % 60;
    string mStr = (minutes == 1) ? " minute" : " minutes";
    string sStr = (seconds == 1) ? " second": " seconds";
    cout << "Longest through time was " << minutes << mStr << " and " << seconds << sStr << ".\n";
    
}