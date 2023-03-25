#include "Header.h"

/////////////////
// Constructor //
/////////////////

// Default construcotr
convertTo::convertTo() {
}

// Param constructor
convertTo::convertTo(string i, string b) :
	input(i), base(b)
{
	toDecimal();				
}




/////////////////////////
// Supporting function //
/////////////////////////
void convertTo::toDecimal() {

}

void convertTo::toOctal() {
}

void convertTo::toBinary() {
}

void convertTo::toHexa() {
}
char convertTo::toChar(int n) {
	if (0 <= n && n <= 9)
		return (n + '0');
	else
		return (n - 10 + 'A');
}


//////////////////////////
// Accessor and Mutator //
//////////////////////////
void convertTo::changeType(string i, string b) {
	input = i;
	base = b;
	decimal = input;
	toDecimal();
}

