#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <memory.h>
#include <time.h>
using namespace std;

#include <chrono>
using namespace chrono;

void printarray(vector<int> &arr) {
    cout << arr.size();
    cout << " array: [";
    bool first = true;
    for (int i : arr) {
        if (!first) {
            cout << ", ";
        }
        first = false;
        cout << i;
    }
    cout << "]\n";
}

void quicksort(vector<int> &arr, int L=-1, int R=0) {
    if (L >= R) {
        return;
    }
    int n = arr.size();
    if (L == -1) {
        L = 0;
        R = n-1;
    }
    int i = L;
    for (int j=L; j<=R-1; ++j) {
        if (arr[j] < arr[R]) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    swap(arr[i], arr[R]);
    quicksort(arr, L, i-1);
    quicksort(arr, i+1, R);
}

// int main() {
int main(int argc, char** argv){
    ofstream fout;
    // fout.open("filein.txt");
    fout.open(argv[1]);

    if (!fout.is_open()) {
        cout << "Error: input file cannot be opened for writing" << endl;
        return -1;
    }

    const int BIG = 5000;
    fout << BIG << '\n';
    for (int i=0; i<BIG; ++i) {
        fout << rand() << '\n';
    }
    fout.close();

    ifstream fin; 
    // fin.open("filein.txt");
    fin.open(argv[1]); //path to the input file

    // Check if file has been opened properly
    if (!fin.is_open()){
        cout << "Error: input file cannot be opened for reading" << endl;
        return -1;
    }  

    /* 
        Read in an array from a file
        First line indicates the length of the array, and the second line contains the actual array.
        
        For example the file could be: 
        5
        5 4 3 2 1
    */

    int N; // length of array
    fin >> N;

    cout << "N: " << N << '\n';

    vector<int> arr (N);
    for (int i = 0; i < N; ++i) {
        fin >> arr[i];
    }

    // confirm we read in the array properly
    // cout << "array contains: \n";
    // for (int i = 0; i < N; ++i) {
    //     cout << arr[i] << '\n';
    // }

    // Timing code:
    auto start_time = steady_clock::now(); // Start time

    // int mx = -(1e9+5);
    // for (int i=0; i<N; ++i) {
    //     if (arr[i] > mx) {
    //         mx = arr[i];
    //     }
    // }

    vector<int> arrcopy = arr;
    for (int t=0; t<100; ++t) {
        quicksort(arr);
        arr = arrcopy;
    }

    auto end_time = steady_clock::now(); // End time
    auto duration = duration_cast<nanoseconds>(end_time - start_time);
    cout << duration.count() << endl;

    return 0;
}

/*
To compile and run your file:
On the command line tool:
1. g++ [pathname of your file] -o [name of the generated executable file] (e.g., > g++ u1234567.cpp -o run_my_code)
2. g++ [pathname of the generated executable file] [pathname of the test file] (e.g., > ./run_my_code ./testfile.txt or > run_my_code testfile.txt for windows)
You are expected to get the output printed your command line.
*/