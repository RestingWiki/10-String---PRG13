#include <iostream>
#include <string>
using namespace std;

#ifndef HEADER_H
#define HEADER_H

class convertTo {

private:
	string input, decimal,octal,hexa,bin;
	int base;

public:
	///////////////// 
	// Constructor //
	/////////////////

	convertTo();						// Default constructor
	convertTo(string i, int b);		// Param constructor

	// Accessor , Mutator
	void changeType(string i, int b);

	void getDecimal() const;
	void getOctal()   const;
	void getBinary()  const;
	void getHexa()    const;

private:
	void toDecimal();
	string toOctal(int n);
	string toBinary(int n);
	string toHexa(int n);

	char toChar( int n);

};

#endif // !HEADER_H

