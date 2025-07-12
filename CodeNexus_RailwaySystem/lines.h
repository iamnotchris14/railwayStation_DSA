//
// Created by Christopher Lee Jia Yung on 12/07/2025.
//

#ifndef LINES_H
#define LINES_H
#include <string>
using namespace std;
//array size for stations
const int MAX_STATIONS = 50;
//declaring station structure
struct {
    string name;
    int index;
};
//declaring line structure
struct Line {
    string lineName;
    Station stations[MAX_STATIONS];
    int stationCount;
};
//declare lines
extern Line putrajayaLine;
extern Line kajangLine;
extern Line monorialLine;

//function for declaring arrays of stations later (can either write in here or in another file)
void initializeLines();


#endif //LINES_H
