#include <iostream>
#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>


using namespace std;


#include "Simulation.h"
#include "Runway.h"

using namespace std;

void readLine(string fileName, vector<Runway>);

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout<<"USAGE: FileReadingExample.exe filename numRunways"<<endl;
		cout<<"where numRunways is an integer > 0."<<endl;
		return 0;
	}

	string filename = argv[1]; // fileName
	int numRunways = stoi(argv[2]); // runway number 

    vector<Runway> runways(numRunways);

    for(int i=0; i<numRunways; i++){
        runways[i] =  Runway();
    }
	
	
	//
	//Opening the file, reading one line (just the first one of the file here) and parsing it
	//

    Simulation* S = new Simulation();
    readLine(filename, runways);

	 //grabbing the next token (reading request type, either landing or takeoff)

}

void readLine(string fileName, vector<Runway>){
    ifstream inputFile;
	inputFile.open(fileName);  // opening the file for reading
	string line;
	
	cout << "The first line of the file contains the following information: " << endl;
	
	if(getline(inputFile, line))  //gets the next line from the file and saves it in 'line', if there is one
	{ 
		stringstream sst(line);  //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
		string token;
		int time = 0;
		string callSign = "";
		string flightNum = "";
		string size = "";
		string requestType = "";
		
		sst >> token;  //grabbing the next token (reading time)
		time = stoi(token); //converting time (string format) to an int
		sst >> callSign;  //grabbing the next token (reading call sign)
		sst >> flightNum;  //grabbing the next token (reading flight number)
		sst >> size;  //grabbing the next token (reading plane size)
		sst >> requestType;  //grabbing the next token (reading request type, either landing or takeoff)
    }

}


