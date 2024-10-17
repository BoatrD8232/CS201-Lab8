#pragma once

#include "Instrument.h"

class Strings : public Instrument {
private:
	int stringCount;
	int fretCount;
	bool bowed;
public:
	//constructors
	//accessors (getters)
	//mutators (setters)
	Strings(string inType, string inName, string inManu, int inYear, int inCost, 
		int inString, int inFret, bool inBow, bool inIsString) : Instrument(inType, inName, inManu, inYear, inCost, inIsString) {
		SetStringCount(inString);
		SetFretCount(inFret);
		SetBowed(inBow);
	}
	void SetStringCount(int inString) { stringCount = inString; }
	void SetFretCount(int inFret) { fretCount = inFret; }
	void SetBowed(bool inBow) { bowed = inBow; }
	int GetStringCount() { return stringCount; }
	int GetFretCount() { return fretCount; }
	bool GetBowed() { return bowed; }
 
	// PRE: Takes in the output stream.
	// POST: Outputs the formatted output to the output file.
	void Print(ofstream& outFile) {
		cout << setw(20) << left << type << setw(20) << name << setw(20) << manufacturer
			<< setw(10) << year << setw(10) << right << cost 
			<< setw (5) << stringCount << setw(5) << fretCount << setw(5) << bowed << endl;
		outFile << setw(20) << left << type << setw(20) << name << setw(20) << manufacturer
			<< setw(10) << year << setw(10) << right << cost
			<< setw(5) << stringCount << setw(5) << fretCount << setw(5) << bowed << endl;
	}
	 
};