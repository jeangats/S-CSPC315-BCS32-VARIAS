// Problem 3: Recursive Algorithms

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Global variables
int TotalMoves = 0;
int CurrentStep = 1;

void MoveDisk(int disk, const string& FromLocation, const string& ToLocation) {
    cout << "Step " << CurrentStep << ": Move package " << disk << " from " << FromLocation << " to " << ToLocation << "." << endl;
    TotalMoves++;
    CurrentStep++;
}

void TowerOfHanoi(int N, const string& FromLocation, const string& ToLocation, const string& buffer, unordered_map<string, vector<int>>& locations) {
    if (N == 1) {
        MoveDisk(locations[FromLocation].back(), FromLocation, ToLocation);
        locations[ToLocation].push_back(locations[FromLocation].back());
        locations[FromLocation].pop_back();
        return;
    }

    TowerOfHanoi(N - 1, FromLocation, buffer, ToLocation, locations);
    MoveDisk(locations[FromLocation].back(), FromLocation, ToLocation);
    locations[ToLocation].push_back(locations[FromLocation].back());
    locations[FromLocation].pop_back();
    TowerOfHanoi(N - 1, buffer, ToLocation, FromLocation, locations);
}

int main() {
    int N;
    cout << "Enter the number of packages to be moved: ";
    cin >> N;

    unordered_map<string, vector<int>> locations = { {"source", vector<int>(N)}, {"buffer", {}}, {"destination", {}} };
    for (int i = 0; i < N; ++i) {
        locations["source"][i] = N - i; // Fill source with disks
    }

    cout << "\nSequence of steps required to move all packages from the source to the destination:" << endl;
    TowerOfHanoi(N, "source", "destination", "buffer", locations);

    cout << "[ / ] All packages have been moved from source to destination." << endl;
    cout << "\nTotal number of moves required for " << N << " packages to be moved from the source location to the destination using a buffer: " << TotalMoves << endl;

    return 0;
}

