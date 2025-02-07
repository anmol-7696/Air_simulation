#include "Simulation.h"

#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>


Simulation::Simulation(){
    this->priorityQueue = new LinkedList;
    this->waitingLine = new LinkedList;
}

LinkedList* Simulation::getPriorityQ(){
    return this->priorityQueue;
}

LinkedList* Simulation::getWaitingLine(){
    return this->waitingLine;
}


void Simulation::readLine(string fileName){
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
		sst >> requestType; 
    }
}