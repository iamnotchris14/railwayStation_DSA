// lines.h
#ifndef LINES_H
#define LINES_H

#include <string>
using namespace std;

// Constants
const int MAX_STATIONS = 50;
const int INF = 9999;

// Structures
struct Station {
    string name;
    int index;
};

struct Line {
    string lineName;
    Station stations[MAX_STATIONS];
    int stationCount;
};

// Extern global variables
extern Line putrajayaLine;
extern Line kajangLine;
extern Line monorailLine;

extern int adjMatrix[MAX_STATIONS][MAX_STATIONS];
extern string stationNames[MAX_STATIONS];
extern int stationCount;

// Function declarations
int getStationIndex(string name);
void addEdge(string from, string to, int weight);
void initializeLines();
// void printStations();
// void printAdjMatrix();

#endif // LINES_H
