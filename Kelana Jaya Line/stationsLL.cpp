#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 50;

// Define structures
struct Station;
struct Connection {
    Station* destination;
    Connection* nextConn;
};

struct Station {
    char name[50];
    Connection* connections;
    Station* nextStation;
};

// Global head of station list
Station* stationHead = nullptr;
int totalStations = 0;

// List of stations for BFS lookup
Station* stationList[MAX];

// Add a new station
Station* addStation(const char stationName[]) {
    Station* s = new Station;
    strcpy(s->name, stationName);
    s->connections = nullptr;
    s->nextStation = nullptr;

    // Add to global list
    if (stationHead == nullptr) {
        stationHead = s;
    } else {
        Station* temp = stationHead;
        while (temp->nextStation) temp = temp->nextStation;
        temp->nextStation = s;
    }

    stationList[totalStations++] = s;
    return s;
}

// Find station pointer by name
Station* findStation(const char stationName[]) {
    Station* temp = stationHead;
    while (temp) {
        if (strcmp(temp->name, stationName) == 0)
            return temp;
        temp = temp->nextStation;
    }
    return nullptr;
}

// Add connection (bidirectional)
void addConnection(const char from[], const char to[]) {
    Station* s1 = findStation(from);
    Station* s2 = findStation(to);
    if (!s1 || !s2) return;

    // Add s2 to s1
    Connection* conn1 = new Connection;
    conn1->destination = s2;
    conn1->nextConn = s1->connections;
    s1->connections = conn1;

    // Add s1 to s2
    Connection* conn2 = new Connection;
    conn2->destination = s1;
    conn2->nextConn = s2->connections;
    s2->connections = conn2;
}

// BFS to find shortest path
void bfs(Station* start, Station* end) {
    int visited[MAX] = {0};
    int parent[MAX];
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < MAX; i++) parent[i] = -1;

    int startIdx = -1, endIdx = -1;
    for (int i = 0; i < totalStations; i++) {
        if (stationList[i] == start) startIdx = i;
        if (stationList[i] == end) endIdx = i;
    }

    if (startIdx == -1 || endIdx == -1) {
        cout << "Invalid stations.\n";
        return;
    }

    queue[rear++] = startIdx;
    visited[startIdx] = 1;

    while (front < rear) {
        int current = queue[front++];
        Connection* conn = stationList[current]->connections;

        while (conn) {
            int neighborIdx = -1;
            for (int i = 0; i < totalStations; i++) {
                if (stationList[i] == conn->destination)
                    neighborIdx = i;
            }

            if (neighborIdx != -1 && !visited[neighborIdx]) {
                queue[rear++] = neighborIdx;
                visited[neighborIdx] = 1;
                parent[neighborIdx] = current;
            }
            conn = conn->nextConn;
        }
    }

    // Trace path
    int path[MAX], pathLen = 0;
    int crawl = endIdx;
    while (crawl != -1) {
        path[pathLen++] = crawl;
        crawl = parent[crawl];
    }

    if (path[pathLen - 1] != startIdx) {
        cout << "No route found.\n";
        return;
    }

    cout << "\n------------------------------------\n";
    cout << "Route Found!\n";
    cout << "------------------------------------\n";
    cout << "Start Station     : " << start->name << endl;
    cout << "End Station       : " << end->name << endl;
    cout << "Total Travel Time : " << (pathLen - 1) * 1.5 << " minutes\n";
    cout << "\nStations Traversed:\n";
    for (int i = pathLen - 1, step = 1; i >= 0; i--, step++) {
        cout << "  " << step << ". " << stationList[path[i]]->name << endl;
    }
}

int main() {
    // Add LRT Kelana Jaya Line stations
    const char* lrtKelana[] = {
        "Gombak", "Taman Melati", "Wangsa Maju", "Setiawangsa", "Jelatek",
        "Dato' Keramat", "Damai", "Ampang Park", "KLCC", "Kampung Baru",
        "Dang Wangi", "Masjid Jamek", "Pasar Seni", "KL Sentral"
    };

    int size = sizeof(lrtKelana) / sizeof(lrtKelana[0]);

    for (int i = 0; i < size; i++) {
        addStation(lrtKelana[i]);
        if (i > 0) addConnection(lrtKelana[i], lrtKelana[i - 1]);
    }

    // User input
    char source[50], destination[50];
    cout << "===========================\n";
    cout << "Klang Valley Transit Route Planner\n";
    cout << "===========================\n";

    cout << "Enter source station: ";
    cin.getline(source, 50);

    cout << "Enter destination station: ";
    cin.getline(destination, 50);

    Station* src = findStation(source);
    Station* dest = findStation(destination);

    if (!src || !dest) {
        cout << "Station not found.\n";
        return 1;
    }

    bfs(src, dest);

    cout << "\n------------------------------------\n";
    cout << "Thank you for using the Klang Valley Transit Route Planner!\n";

    return 0;
}
