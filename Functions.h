#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "Instrument.h"
#include "Strings.h"
using namespace std;


void readFile(ifstream& inFile, ofstream& errFile, vector<Instrument*>& instrumentList);
//PRE: Accept input stream, output file stream (for errors) and empty vector of pointers to an Instrument object
//POST:Reads input stream, writes errors to the error file & updates instrumentList with valid data

char displayMenu();
//PRE: none
//POST:returns a valid menu entry

void listInstruments(ofstream& outFile, vector<Instrument*> instrumentList);
//PRE:  output file is sent (for printing purposes) along with instrumentList containing valid pointer values
//POST: a report of instruments is printed to cout & to outFile

void findInstruments(ofstream& outFile, ofstream& errFile, vector<Instrument*> instrumentList);
//PRE:  output file is sent (for printing purposes) along with instrumentList containing valid pointer values
//POST: the user is prompted to enter the name of an instrument.
//      a report of instruments is printed to cout & to outFile
//      if no instrument is found, a message is displayed to standard output & to error file

void listManufacturers(ofstream& outFile, ofstream& errFile, vector<Instrument*>  instrumentList);
//PRE:  output file is sent (for printing purposes) along with instrumentList containing valid pointer values
//POST: a report of instruments is printed to cout & to outFile



