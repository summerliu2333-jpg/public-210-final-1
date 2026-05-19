//COMSC-210-5068, Final-1, Yang Liu
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

void print_in_range(map<string, int>& airports, int low, int high);

int main() {
    //M1
    ifstream infile("210-final-1-SP26.txt");
    map<string, int> airports;
    string origin, destination;

    while (infile >> origin >> destination) {
        if (airports.find(origin) == airports.end()) airports[origin] = 0;
        if (airports.find(destination) == airports.end()) airports[destination] = 0;
        airports[origin]++;
        airports[destination]++;
    }
    infile.close();
 
    cout << "All airport traffic counts:" << endl;
    for (auto entry : airports) {
        cout << entry.first << ' ' << entry.second << endl;
    }

    //M2
    int maxCount = 0;
    for (auto entry : airports) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
        }
    }
 
    cout << "\nBusiest airport(s) with count " << maxCount << ":" << endl;
    for (auto entry : airports) {
        if (entry.second == maxCount) {
            cout << entry.first << " " << entry.second << endl;
        }
    }

    //M3
    cout << endl;
    print_in_range(airports, 5, 8);
    cout << endl;
    print_in_range(airports, 9, 12);

    return 0;
}

//M3
void print_in_range(map<string, int>& airports, int low, int high) {
    cout << "Airports with traffic in range [" << low << ", " << high << "]:" << endl;
    for (auto entry : airports) {
        if (entry.second >= low && entry.second <= high) {
            cout << entry.first << " " << entry.second << endl;
        }
    }
}
