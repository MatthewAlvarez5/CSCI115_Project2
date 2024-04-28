/******************************************************************************
Author(s): Matthew Alvarez, Jovani Benavides, Mateo, Nestor
Course: CSCI 115 Project Part 2
Assignment: Two Sum

*******************************************************************************/
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void bruteForce(vector<int>& S, int x) {
    for (int i = 0; i < S.size(); i++) { // 0 to n
        for (int j = i + 1; j < S.size(); j++) { // i+1 to n
            if (S[i] + S[j] == x) {  
                cout << S[i] << "+" << S[j] << endl;  // print if sum to x
            }
        }
    }
    return;
}

void efficient(vector<int>& S, int x) {
    bool* seen = new bool[x];    // list of seen integers
    bool* printed = new bool[x]; // list of printed integers

    // intialize arrays (time does not change - ignore in pseudocode)
    for (int i = 0; i < x; i++) {
        seen[i] = false;
        printed[i] = false;
    }

    for (int i = 0; i < S.size(); i++) { // 0 to n
        int missingNum = x - S[i]; // getting number needed for x
        
        seen[S[i]] = true;    
        
        // missingNum has been seen and not printed
        if (seen[missingNum] && !printed[S[i]]) {    
            cout << S[i] << "+" << missingNum << endl;
            // add both numbers to printed to avoid duplicate combinations
            printed[missingNum] = true;
            printed[S[i]] = true;
        }
    }
    return;
}


int main()
{
    int n; // # of integers in set
    int x; // check for factors

    cout << "Enter the number of integers in the set: ";
    cin >> n;

    cout << "Enter the number to find possible factors: ";
    cin >> x;
    vector<int> arrS; // set of integers

    // fill set S with random integers
    for (int i = 0; i < n; i++) {
        arrS.push_back(rand()%x);
    }
    cout << endl;

    // call and time function
    cout << endl << "Brute Force: \n";
    clock_t start = clock();
    bruteForce(arrS, x);
    clock_t end = clock();
    cout << "\nTime taken:\t\t\t" << (double)(end - start) * 1000.0 / CLOCKS_PER_SEC << " milliseconds" << endl;

    // call and time function
    cout << endl << "Efficient: \n";
    clock_t start2 = clock();
    efficient(arrS, x);
    clock_t end2 = clock();
    cout << "\nTime taken:\t\t\t" << (double)(end2 - start2) * 1000.0 / CLOCKS_PER_SEC << " milliseconds" << endl;

    return 0;
}

