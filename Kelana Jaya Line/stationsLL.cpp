#include <iostream>
using namespace std;

struct Station {
	string name;
	int eta;
	Station* next;
};

int main() {
	const int NUM_STATIONS = 23;
	string stationNames[NUM_STATIONS] = {
		"Putra Heights", "Subang Alam", "Alam Megah", "USJ 21", "Wawasan",
		"Taipan", "USJ 7", "SS18", "SS15", "Subang Jaya", "CGC Glenmarie",
		"Ara Damansara", "Lembah Subang", "Kelana Jaya", "Taman Bahagia",
		"Taman Paramount", "Asia Jaya", "Taman Jaya", "Universiti",
		"Kerinchi", "Abdullah Hukum", "Bangsar", "KL Sentral"
	};

	int defaultETA = 2;
	Station* head = nullptr;
	Station* tail = nullptr;

	for (int i = 0; i < NUM_STATIONS; i++) {
		Station* newStation = new Station;
		newStation->name = stationNames[i];
		newStation->eta = (i == NUM_STATIONS - 1) ? 0 : defaultETA;
		newStation->next = nullptr;

		if (head == nullptr) {
			head = newStation;
			tail = newStation;
		} else {
			tail->next = newStation;
			tail = newStation;
		}
	}

	Station* current = head;
	while (current != nullptr) {
		cout << current->name;
		if (current->next != nullptr)
			cout << " -> ETA: " << current->eta << " mins -> ";
		current = current->next;
	}

	return 0;
}
