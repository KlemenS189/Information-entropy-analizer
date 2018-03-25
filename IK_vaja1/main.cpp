/**
* Copyright (c) 2012 University of Ljubljana, Faculty of Electrical Engineering.
* All rights reserved. Licensed under the Academic Free License version 3.0.
*
* @author Klemen Štrajhar
* @version 24/03/2018
*
* Program za izračun entropije besedila. Uporablja se std::unordered_map za shranjevanje podatka, kolikokrat se določeno zaporedje
* znakov pojavi v besedilu.
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include <math.h> 
#include <unordered_map>
#include "Dictionary.h"

using namespace std;


int main(int argc, char* argv[]) {
	unordered_map<std::string, int> u_dict;
	bool showMap = 0;
	bool wordBased = 0;
	if (argc <= 2) {
		std::cout << "\nUser must provide the following arguments -> name_of_file, bufferSize\nOptional parameters are -m for showing all combinations of map and -w for entropy analysis based on words.\nExiting...\n ";
		exit(3);
	}

	for (int i = 3; i < argc; i++) {
		std::string param = argv[i];
		if (param == "-m") {
			showMap = 1;
		}
		if (param == "-w") {
			wordBased = 1;

		}
	}
	const int bufferSize = stoi(argv[2]);
	//const short int showMap = stoi(argv[3]);
	if (!wordBased) {
		std::cout << "\nStarting information entropy analysis with buffer size of: " << bufferSize << " bytes." << std::endl;
	}
	else {
		std::cout << "\nStarting information entropy analysis based on words" << std::endl;
	}
	

	char *buffer = new char[bufferSize];
	long int counter = 0;

	ifstream stream(argv[1], ios::in | ios::binary);
	if (stream) {

		// Reads 
		stream.seekg(0, stream.end);
		int lengthOfFile = (int) stream.tellg();
		stream.seekg(0, stream.beg);
		

		if (bufferSize > lengthOfFile) {
			// Exits the process if size of byte pairs is larger than length of file
			cerr << "Error: 1 => " << "Size of byte pairs cannot exceed length of file." << endl;
			exit(1);
		}


		cout << "Length of file: " << lengthOfFile << " bytes." << endl;

		for (int i = 0; i <= lengthOfFile - bufferSize; i++) {
			counter++;
			stream.seekg(i);
			stream.read(buffer, bufferSize);
			string str(buffer, bufferSize);

			if (!wordBased) {
				// Del za izvajanje analize na podlagi
				unordered_map<std::string, int>::iterator it = u_dict.find(str);
				if (it != u_dict.end()) {
					u_dict[str]++;
				}
				else {
					u_dict[str] = 1;
				}
			}
			else {



			}

						
		}
		int length_of_umap = (int) u_dict.size();
		std::cout << "Number of elements in dictionary(unordered_map): " << length_of_umap <<std::endl;
		double entropy = 0;

		std::unordered_map<std::string, int>::iterator it = u_dict.begin();

		while (it != u_dict.end()) {
			double logged_number = it->second;
			double log_value = logged_number / counter;
			log_value = log_value * log2(log_value);
			entropy += log_value; 

			if (showMap) {
				std::string word = it->first;
				std::cout << word << " :: " << logged_number << std::endl;
			}

			it++;
		}
		cout << "Entropy value of selected text: " << -entropy/bufferSize << " bits." << endl;

	}
	else {
		cerr << "Error: 2 => " << "Error reading the selected file." << endl;
		exit(2);
	}

	//system("pause");
	delete[] buffer;;
	return 0;
}
