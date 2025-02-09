#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Simulation.h"
#include "Runway.h"
#include "Plane.h"
#include "SmallPlane.h"

int runwaysInUse = 0; // Counter to keep track of runways under use 
int atcId = 1;

void processFile(string fileName, vector<Runway>& runways, Simulation* sim);
Event* createEvent(int t, string callsign, string num, string size, string request);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "USAGE: FileReadingExample.exe filename numRunways" << endl;
        cout << "where numRunways is an integer > 0." << endl;
        return 0;
    }

    string filename = argv[1];
    int numRunways = stoi(argv[2]);

    vector<Runway> runways(numRunways);

    for (int i = 0; i < numRunways; i++) {
        runways[i] = Runway();
    }

    // Create Simulation object
    Simulation* S = new Simulation();

    // Read and process events from file
    processFile(filename, runways, S);

    delete S;
    return 0;
}

void processFile(string fileName, vector<Runway>& runways, Simulation* sim)
{
    ifstream inputFile(fileName);
    string line;

    if (!inputFile) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    while (getline(inputFile, line)) // Read each line
    {
        stringstream sst(line);
        string token;
        int time = 0;
        string callSign, flightNum, size, requestType;

        sst >> token;
        time = stoi(token);
        sst >> callSign >> flightNum >> size >> requestType;

        // Create event
        Event* e = sim->createEvent(time, callSign, flightNum, size, requestType,atcId);
		atcId++;

        if (e) {
            // Schedule the event in Simulation
            sim->scheduleEvent(e,runways);
        }

        // Process events before reading the next line
        //while (sim->hasPendingEvents()) {
        //    sim->processNextEvent();
        //}
    }

    inputFile.close();
}





