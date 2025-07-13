//
// Created by Christopher Lee Jia Yung on 12/07/2025.
//
#include "putrajayaLine.h"
#include <iostream>
using namespace std;

int main()
{
    initializePutrajayaLine();
    cout << "Putrajaya Line: " << endl;

    // display
    for (int i = 0; i < putrajayaLine.stationsCount; ++i) {
        cout << putrajayaLine.stations[i].name;

        if (i < putrajayaLine.stationsCount - 1) {
            int fromIndex = putrajayaLine.stations[i].index;
            int toIndex = putrajayaLine.stations[i + 1].index;
            int travelTime = graph[fromIndex][toIndex];

            cout << " -" << travelTime << "min-> ";
        }
    }
    cout << endl;
}
