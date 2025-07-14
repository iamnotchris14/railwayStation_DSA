//
// Created by Christopher Lee Jia Yung on 13/07/2025.
//
// main.cpp
#include <iostream>
#include "lines.h"
using namespace std;

bool stationExists(string name) {
    for (int i = 0; i < stationCount; i++) {
        if (stationNames[i] == name) return true;
    }
    return false;
}

int main() {
    initializeLines();
    // printStations();        /* debug testing */
    // printAdjMatrix();

    string currentStation = "Titiwangsa";
    string destination;

    cout << "\nYou're now at " << currentStation << " station!" << endl;
    cout << "Where are you heading to? ";
    getline(cin, destination); // use getline to support spaces

    if (!stationExists(destination)) {
        cout << "Sorry, the station \"" << destination << "\" does not exist in the system." << endl;
        return 1;
    }

    cout << "Finding shortest path from " << currentStation << " to " << destination << "..." << endl;

    // findShortestPath(currentStation, destination);

    return 0;
}
