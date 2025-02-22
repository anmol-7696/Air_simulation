//-----------------------------------------
// NAME		: ANMOLPREET SINGH
// STUDENT NUMBER	: 7983556
// COURSE		: COMP 2150
// INSTRUCTOR	: OLIVIER TREMBLAY-SAVARD
// ASSIGNMENT	: assignment 2
//
// REMARKS: EVENT DRIVEN SIMULATIN FOR AIR TRAFFIC CONTROL
//-----------------------------------------

// includes for file reading
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

// inludes class header files to work with
#include "Simulation.h"
#include "Runway.h"

using namespace std;

int runwaysInUse = 0; // Counter to keep track of runways under use
int atcId = 1;        // Counter for the atc Id for the planes

// forward declaration for functions
void processFile(string fileName, vector<Runway> &runways, Simulation *sim);
Event *createEvent(int t, string callsign, string num, string size, string request);
void printMessage(vector<Runway> , Simulation* sim);

int main(int argc, char *argv[])
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

    for (int i = 0; i < numRunways; i++)
    {
        runways[i] = Runway();
        runways[i].setName(i + 1);
    }

    // Create Simulation object
    Simulation *S = new Simulation();

    // Read and process events from file
    processFile(filename, runways, S);

    delete S;
    return 0;
}

//-------------------------------------------------------------------------------
// processFile
//
// PURPOSE: Reads file and starts simulation for each line of the input text
// PARAMETERS: fileName -> name of the file
//             runways ->  vector of runways
//             sim     ->  object of Simulation class created in main function
// Returns: void
//--------------------------------------------------------------------------------

void processFile(string fileName, vector<Runway>& runways, Simulation *sim)
{
    ifstream inputFile(fileName);
    string line;

    if (!inputFile)
    {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    cout << "\n"
         << endl;
    cout << "Simulatin begins..." << endl;

    while (getline(inputFile, line))
    {
        stringstream sst(line);
        string token;
        int time = 0;
        string callSign, flightNum, size, requestType;

        sst >> token;
        time = stoi(token);
        sst >> callSign >> flightNum >> size >> requestType;

        // Create event
        Event *ev = sim->createEvent(time, callSign, flightNum, size, requestType, atcId);
        atcId++;

        // schedule event are creating it
        sim->scheduleEvent(ev, runways);

        if (sim->getPriorityQ() && !(sim->getPriorityQ()->isEmpty()))
        {
            // process event is called
            sim->processEvent(runways);
        }
    }

    inputFile.close();
    printMessage(runways, sim);
}

//-------------------------------------------------------------------------------
// printMessage 
//
// PURPOSE: prints the final message after the simulation ends 
// PARAMETERS: runways -> vector of runways 
//             sim     ->  object of Simulation class created in main function
// Returns: void
//--------------------------------------------------------------------------------

void printMessage(vector<Runway> runways, Simulation* sim){
    cout << "#######################\n"
         <<  "The simulation has ended.\n"
         <<   "The number of runways was " + std::to_string(runways.size()) + "\n"
         <<   "The total amount of time wasted because runways were not available was " + std::to_string(sim->getTimeWasted()) + " minutes." + "\n"
         <<   "#######################.\n" 
         << endl;
}
