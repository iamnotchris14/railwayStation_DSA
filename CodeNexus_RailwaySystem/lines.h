//
// Created by Christopher Lee Jia Yung on 12/07/2025.
//

#ifndef LINES_H
#define LINES_H

#include <string>
using namespace std;

// array size for stations
const int MAX_STATIONS = 50;
const int INF = 9999;  // For shortest path use

// declare Station structure
struct Station {
    string name;
    int index; // unique index used for adjacency matrix
};

// declare Line structure
struct Line {
    string lineName;
    Station stations[MAX_STATIONS];
    int stationCount;
};

// declare all lines
extern Line putrajayaLine;
extern Line kajangLine;
extern Line monorailLine;

// adjacency matrix for all stations combined
extern int adjMatrix[MAX_STATIONS][MAX_STATIONS];

// map station index to name (manually created)
extern string stationNames[MAX_STATIONS];
extern int stationCount;

// function to initialize all lines and connections
void initializeLines();

#endif //LINES_H
