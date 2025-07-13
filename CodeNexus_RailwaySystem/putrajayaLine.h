//
// Created by HASHIKA KESHREEN on 7/14/2025.
//

#ifndef PUTRAJAYALINE_H
#define PUTRAJAYALINE_H

#include <string>
using namespace std;

const int MAX_STATIONS = 50;

struct Station {
    string name;
    int index;
};

struct Line{
    string lineName;
    Station stations[MAX_STATIONS];
    int stationsCount;
};

const int MAX_VERTICES = 20; // or however many total stations
int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix

// Define all stations for Putrajaya line
Line putrajayaLine = {
    "Putrajaya Line",
    {
                {"Titiwangsa", 0},
                {"Hospital KL", 1},
                {"Raja Uda", 2},
                {"Ampang Park", 3},
                {"Persiaran KLCC", 4},
                {"Conlay", 5}
    },
    6 // total stations
};

// Function to initialize Putrajaya line graph
void initializePutrajayaLine() {
    // Create edges in the adjacency matrix
    graph[0][1] = graph[1][0] = 2; // Titiwangsa - Hospital KL
    graph[1][2] = graph[2][1] = 1; // Hospital KL - Raja Uda
    graph[2][3] = graph[3][2] = 3; //Raja Uda - Ampang Park
    graph[3][4] = graph[4][3] = 2; //Ampang Park - P KLCC
    graph[4][5] = graph[5][4] = 2; //P KLCC - Conlay
}


#endif //PUTRAJAYALINE_H
