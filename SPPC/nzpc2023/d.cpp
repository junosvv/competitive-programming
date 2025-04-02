// d.cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string target;
    cin >> target;
    string guess;
    int numlines = 0;
    cin.ignore(1, '\n');
    while (getline(cin, guess)) {
        if (guess == "GIVE UP") {
            break;
        }
        // First check the number of bulls:
        int bulls = 0, cows = 0;
        vector<int> disregard;
        for (int i = 0; i < 4; i++) {
            if (guess[i] == target[i]) {
                bulls++;
                disregard.push_back(i);
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (find(disregard.begin(), disregard.end(), j) != disregard.end()) {
                        continue;
                    }
                // check
                if (guess[i] == target[j]) {
                    cows++;
                    disregard.push_back(j);
                }
            }
        }
        string bullStr = (bulls == 1) ? " bull" : " bulls";
        string cowStr = (cows == 1) ? " cow" : " cows";
        cout << guess << " Score " << bulls << bullStr << " and " << cows << cowStr << ".\n";
        numlines++;
        if (target == guess) {
            cout << "The word was guessed in " << numlines << ".\n";
            exit(0);
        }
    }
    cout << "The word was not guessed. Answer: " << target << ".\n";
}