#include "Header.h"

/////////////////
// Constructor //
/////////////////

// Default construcotr
convertTo::convertTo() {
}

// Param constructor
convertTo::convertTo(string i, int b) :
	input(i), base(b)
{
	toDecimal();

	// Convert the data into different bases
	int n = stoi(decimal);
	octal = toOctal(n);
	bin = toBinary(n);
	hexa = toHexa(n);
}


/////////////////////////
// Supporting function //
/////////////////////////
void convertTo::toDecimal() {
	
	if (base == 10)
		return;
	else if (base == 2 || base == 16 || base == 8)
	{
		int len = input.length() -1;
		int temp_B = 1;
		int value = 0;

		while (len >= 0)
		{

			value += (input.at(len) - '0') * temp_B;
			temp_B *= base;
				len--;
		}
		
		decimal = to_string(value);
	}

}

string convertTo::toOctal(int n) {
	if (n < 8)
		return to_string(n);
	else
	{
		return toOctal(n / 8) + toChar(n%8);
	}
}

string convertTo::toBinary(int n) {
	if (n == 0)
		return "0";

	string value = "";
	while (n > 0)
	{
		int digit = n % 2;
		value += to_string(digit);
		n /= 2;
	}

	return value;
}

string convertTo::toHexa(int n) {
	if (n == 0)
		return "0";
	

	string value = "";
	while (n > 0)
	{
		value += string("") + toChar(n % 16);
		n /= 16;
	}

	return value;
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
void convertTo::changeType(string i, int b) {
	input = i;
	base = b;

	// Update the varibales with the new data
	toDecimal();
	int n = stoi(decimal);
	octal = toOctal(n);
	bin = toBinary(n);
	hexa = toHexa(n);
	
}
void convertTo::getBinary()  const{
	cout <<"Binary: " << bin << endl;
}

void convertTo::getOctal() const {
	cout << "Octal: " << octal << endl;
}

void convertTo::getHexa() const {
	cout << "Hexadcimal: " << hexa << endl;
}

