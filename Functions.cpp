#include "Functions.h"
 
void readFile(ifstream& inFile, ofstream& err, vector<Instrument*>& instrumentList) {

    string inRec, token;
    string type, name, manu;
    int year, cost, numStr, numFr;
    bool isBowed;
    Instrument* tempInst;
    vector<string> tokens;
    while (getline(inFile, inRec)) {
        stringstream inSS(inRec);
        tokens.clear();
        while (getline(inSS, token, ','))  
            tokens.push_back(token);
        
        try {
            type = tokens.at(0);
            name = tokens.at(1);
            manu = tokens.at(2);
            year = stoi(tokens.at(3));
            cost = stoi(tokens.at(4));
            if (tokens.at(5).length() > 0) {
                numStr = stoi(tokens.at(5));
                numFr = stoi(tokens.at(6));
                isBowed = stoi(tokens.at(7));
                tempInst = new Strings(type, name, manu, year, cost, numStr, numFr, isBowed, true);
            }
            else {
                tempInst = new Instrument(type, name, manu, year, cost, false);
            }
            instrumentList.push_back(tempInst);
        }
        catch (const invalid_argument & e) {
            err << left << "Error: " << setw(28) << e.what() << " - " << inRec << endl;
            continue;
        }
        catch (...) {
            err << left << "Error: " << " - " << inRec << endl;
            continue;
        }
    }
      
}

char displayMenu() {
    char choice = '5';
    string temp;

    cout << "\nWelcome to the Instrument Database\n";

    while (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
        cout << "Your choices are: \n";
        cout << "1. List All Instruments\n";
        cout << "2. Find Specific Instruments\n";
        cout << "3. List All Instruments for a Manufacturer\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
            cout << "\nPlease enter a valid value!\n";
            getline(cin, temp);
        }
    }
    getline(cin, temp);
    return choice;
}


void listInstruments(ofstream& outFile, vector<Instrument*> instrumentList) {
    outFile << "\n\nINSTRUMENT LIST\n";
    outFile << setw(20) << left << "TYPE" << setw(20) << "NAME" << setw(20)
         << "MANUFACTURER" << setw(10) << "YEAR BUILT" << right << setw(10) << "COST" << endl;

    cout << "\n\nINSTRUMENT LIST\n";
    cout << setw(20) << left << "TYPE" << setw(20) << "NAME" << setw(20)
        << "MANUFACTURER" << setw(10) << "YEAR BUILT" << right << setw(10) << "COST" << endl;

    for (int i = 0; i < instrumentList.size(); ++i) {
        if (instrumentList.at(i)->isStringed()) {
            static_cast<Strings*>(instrumentList.at(i))->Print(outFile);
        }
        else {
            instrumentList.at(i)->Print(outFile);
        }
    }
    outFile << "\n\n" << endl;
}

void findInstruments(ofstream& outFile, ofstream& errFile, vector<Instrument*>  instrumentList) {
    string inType;
    int count = 0;
    cout << "Provide instrument type: " << endl;
    cin >> inType;
    cout << "Instruments containing the word " << inType << endl;
    outFile << "Instruments containing the word " << inType << endl;
    for (int i = 0; i < instrumentList.size(); ++i) {
        if (instrumentList.at(i)->GetType().find(inType) != string::npos) {
            if (instrumentList.at(i)->isStringed()) {
                static_cast<Strings*>(instrumentList.at(i))->Print(outFile);
            }
            else {
                instrumentList.at(i)->Print(outFile);
            }
            count++;
        }
    }
    if (count == 0) {
        cout << "No instruments found." << endl;
        errFile << "Error: No instruments found." << endl;
    }
    outFile << "\n\n" << endl;
}

void listManufacturers(ofstream& outFile, ofstream& errFile, vector<Instrument*>  instrumentList){
    string inMan;
    int count = 0;
    cout << "Provide instrument manufacturer: " << endl;
    cin >> inMan;
    cout << "Manufacturers containing the word " << inMan << endl;
    outFile << "Manufacturers containg the word " << inMan << endl;
    for (int i = 0; i < instrumentList.size(); ++i) {
        if (instrumentList.at(i)->GetManu().find(inMan) != string::npos) {
            if (instrumentList.at(i)->isStringed()) {
                static_cast<Strings*>(instrumentList.at(i))->Print(outFile);
            }
            else {
                instrumentList.at(i)->Print(outFile);
            }
            count++;
        }
    }
    if (count == 0) {
        cout << "No instruments found." << endl;
        errFile << "Error: No instruments found." << endl;
    }
    outFile << "\n\n" << endl;
}