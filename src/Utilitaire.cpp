#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;


//------------------------------------------------------ Include personnel
#include "Utilitaire.h"

void Utilitaire::afficherMenuPrincipal() {
	cout << endl;
	cout << "|******************************************" << endl;
	cout << "| 0 - Load file                            " << endl;
	cout << "| 1 - Add a path							" << endl;
	cout << "| 2 - Display the catalog					" << endl;
	cout << "| 3 - Search for a course					" << endl;
	cout << "| 4 - Search for a course (advanced mode)	" << endl;
	cout << "| 5 - Save catalog                         " << endl;
	cout << "| 6 - Exit									" << endl;
	cout << endl;
	cout << "Enter the corresponding number : ";
}

void Utilitaire::afficherMenuLoadSave() {
	cout << endl;
	cout << "Select :                   			" << endl;
	cout << "0. All path			    			" << endl;
	cout << "1. Only direct route       			" << endl;
	cout << "2. Only multi-city travel  			" << endl;
	cout << "3. From the Departure City   			" << endl;
	cout << "4. From the Arrival City    		    " << endl;
	cout << "5. From city of departure and arrival  " << endl;
	cout << endl;
	cout << "Enter the corresponding number : ";
}

void Utilitaire::afficherChoixInvalide(const int borneInf, const int borneSup) {
	cout << "Invalid choice. Please enter a number between " << borneInf << " and " << borneSup << " !" <<endl; 
}

inline bool exists_file (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}
