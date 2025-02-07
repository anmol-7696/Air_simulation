#include <iostream>
using namespace std;


#include "Simulation.h"

using namespace std;

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
	
	
	//
	//Opening the file, reading one line (just the first one of the file here) and parsing it
	//

    Simulation* S = new Simulation();

	 
	}

