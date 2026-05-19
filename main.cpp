#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

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

    return 0;
}