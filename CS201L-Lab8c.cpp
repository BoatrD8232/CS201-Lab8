// CS201L-Lab8c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Functions.h"

int main() {
    ifstream inFile;
    ofstream outFile, errFile;

    inFile.open("instrument.csv");
    outFile.open("report.txt");
    errFile.open("error.txt");

    if (!inFile.good() || !outFile.good() || !errFile.good()) {
        cout << "Error opening files\n";
        return -1;
    }

    vector<Instrument*> instrumentList;
    readFile(inFile, errFile, instrumentList);
    char choice;
    choice = displayMenu();
    while (choice != '4') {
        switch (choice) {
        case '1':
            listInstruments(outFile, instrumentList);
            break;
        case '2':
            findInstruments(outFile, errFile, instrumentList);
            break;
        case '3':
            listManufacturers(outFile, errFile, instrumentList);
            break;
        }
        choice = displayMenu();
    }

}
