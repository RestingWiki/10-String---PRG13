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
			if (base == 2 || base == 8)
				value += (input.at(len) - '0') * temp_B;
			else if (base == 16)
				value += toDigit(input.at(len)) * temp_B;


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
int convertTo::toDigit(char c) {
	int value = c - '0';
	if (0 <= value && value == 9)
		return value;
	else if (c == 'A')
		return 10;
	else if (c == 'B')
		return 11;
	else if (c == 'C')
		return 12;
	else if (c == 'D')
		return 13;
	else if (c == 'E')
		return 14;
	else if (c == 'F')
		return 15;
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
void convertTo::getDecimal() const {
	cout << "Decimal: " << decimal << endl;
}

