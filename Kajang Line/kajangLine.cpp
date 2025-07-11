#include <iostream>
using namespace std;

struct Station {
    string name;
    int time;
    Station* nextStation;
};

//Display function
void displayStationTraversed(Station* start, string destination)
{
    //declare current
    Station* current = start;
    int count = 1;

    cout << "Station Traversed: " << endl;
    while(current != NULL && current -> name != destination)
    {
        cout << count++ << ". " << current -> name << endl;

        //current moving 1 step
        current = current -> nextStation;
    }
    if (current != NULL) {
        cout << count++ << ". " << current -> name << endl;
    }
}

int main() {
    Station* head;
    Station* current;
    Station* start;
    head = current = NULL;

    string kajangLine[] = {"Pasar Seni", "Merdeka", "Bukit Bintang", "Tun Razak Exchange",
    "Cochrane", "Maluri", "Taman Pertama"};

    int travelTime[] = {3, 2, 4, 1, 1, 3};

    int totalStations = sizeof(kajangLine) / sizeof(kajangLine[0]);
    for (int i = 0; i < totalStations; ++i) {
        Station* newStation = new Station;
        newStation->name = kajangLine[i];
        newStation->nextStation = nullptr;

        if (head == nullptr) {
            head = newStation;
            current = newStation;
        } else {
            current->nextStation = newStation;
            current -> time = travelTime[i-1];
            current = newStation;
        }
    }

    cout << "==========================="<<endl;
    cout << "Klang Valley Transit Route Planner" << endl;
    cout << "===========================" << endl;
    cout<< "\tKajang Line" << endl;

    current = head;
    while(current != NULL)
    {
        cout <<  current -> name;
        if (current -> nextStation != NULL) {
            cout << " --" << current -> time << " min(s)-> ";
        }
        //current moving 1 step
        current = current -> nextStation;
    }
    cout << endl;

    current = head;
    string source, destination;
    cout << "Enter source station: ";
    getline(cin, source);
    cout << "Enter destination station: ";
    getline(cin, destination);

    while (current != NULL && current -> name != source) {
        current = current -> nextStation;
    }

    start = current;

    int totalTravelTime = 0;
    while (current != NULL && current -> name != destination) {
        totalTravelTime += current -> time;
        current = current -> nextStation;
    }

    cout << "Total travel time: " << totalTravelTime << endl;
    displayStationTraversed(start, destination);
}

//
// Created by HASHIKA KESHREEN on 7/9/2025.
//
