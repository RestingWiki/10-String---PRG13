#include <iostream>
#include <string>
using namespace std;

#ifndef HEADER_H
#define HEADER_H

class convertTo {

private:
	string input, base, decimal;

public:
	///////////////// 
	// Constructor //
	/////////////////

	convertTo();						// Default constructor
	convertTo(string i, string b);		// Param constructor

	// Accessor , Mutator
	void changeType(string i, string b);

	void getDecimal();
	void getOctal();
	void getBinary();
	void getHexa();

private:
	void toDecimal();
	void toOctal();
	void toBinary();
	void toHexa();

	char toChar( int n);

};

#endif // !HEADER_H

