#pragma once
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class Instrument {
protected:
	string type;
	string name;
	string manufacturer;
	int year;
	int cost;
	bool stringed;
public:
    // Constructors
    // Getters (Accessors)
    // Setters (Mutators)
	// print
	Instrument(string inType, string inName, string inManu, int inYear, int inCost, bool inIsString) {
		SetType(inType);
		SetName(inName);
		SetManu(inManu);
		SetYear(inYear);
		SetCost(inCost);
		stringed = inIsString;
	}
	void SetType(string inType) {type = inType;}
	void SetName(string inName) {name = inName;}
	void SetManu(string inManu) {manufacturer = inManu;}
	void SetYear(int inYear) {year = inYear;}
	void SetCost(int inCost) {cost = inCost;}
	string GetType() { return type; }
	string GetName() { return name; }
	string GetManu() { return manufacturer; }
	int GetYear() { return year; }
	int GetCost() { return cost; }
	bool isStringed() { return stringed; }
	// PRE: Takes in the output stream.
	// POST: Outputs the formatted output to the output file.
	void Print(ofstream& outFile) {
		cout << setw(20) << left << type << setw(20) << name << setw(20) << manufacturer
			<< setw(10) << year << setw(10) << right << cost << endl;
		outFile << setw(20) << left << type << setw(20) << name << setw(20) << manufacturer
			<< setw(10) << year << setw(10) << right << cost << endl;
	}
};