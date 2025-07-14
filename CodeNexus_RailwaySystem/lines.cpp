// lines.cpp
#include "lines.h"
#include <iostream>
using namespace std;

// global variable definitions
Line putrajayaLine;
Line kajangLine;
Line monorailLine;

int adjMatrix[MAX_STATIONS][MAX_STATIONS];
string stationNames[MAX_STATIONS];
int stationCount = 0;

// Get or assign station index
int getStationIndex(string name) {
    for (int i = 0; i < stationCount; i++) {
        if (stationNames[i] == name)
            return i;
    }
    stationNames[stationCount] = name;
    return stationCount++;
}

// adding bidirectional connection
void addEdge(string from, string to, int weight) {
    int u = getStationIndex(from);
    int v = getStationIndex(to);
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

// initializing stations and connections
void initializeLines() {
    for (int i = 0; i < MAX_STATIONS; i++)
        for (int j = 0; j < MAX_STATIONS; j++)
            adjMatrix[i][j] = (i == j) ? 0 : INF;

    // Monorail Line
    monorailLine.lineName = "Monorail Line";
    string mono[] = {
        "Titiwangsa", "Chow Kit", "Medan Tuanku", "Bukit Nanas",
        "Raja Chulan", "Bukit Bintang"
    };
    monorailLine.stationCount = 6;
    for (int i = 0; i < monorailLine.stationCount; i++) {
        int idx = getStationIndex(mono[i]);
        monorailLine.stations[i] = { mono[i], idx };
        if (i > 0) addEdge(mono[i - 1], mono[i], 2);
    }

    // Kajang Line
    kajangLine.lineName = "Kajang Line";
    string kajang[] = {
        "Bukit Bintang", "Tun Razak Exchange TRX"
    };
    kajangLine.stationCount = 2;
    for (int i = 0; i < kajangLine.stationCount; i++) {
        int idx = getStationIndex(kajang[i]);
        kajangLine.stations[i] = { kajang[i], idx };
        if (i > 0) addEdge(kajang[i - 1], kajang[i], 2);
    }
}


