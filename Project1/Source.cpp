#include <iostream>
#include "Header.h"
using namespace std;


//////////////////////////
// Function declaration //
//////////////////////////
bool checkInput(string s, string b);


int main() {

	// User's input
	string base, number;

	// Check input for different base
	do {
		cout << "Enter base: " << endl;
		cin >> base;
		cout << "Enter number: " << endl;
		cin >> number;
	} while (!checkInput(number,base));



	// Display results
	convertTo converter(number, stoi(base));
	converter.getDecimal();
	converter.getBinary();
	converter.getOctal();
	converter.getHexa();
	

	return 0;




}


/////////////////////////
// Function definition //
/////////////////////////
bool checkInput(string s, string b) {
	int base = stoi(b);
	int len = s.length();


	char arr[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

	for (int i = 0; i < len; i++)
	{
		// Base 2,8
		if (0 <= base && base <= 9)
		{
			if (!(48 <= s.at(i) && s.at(i) <= 57))
				return false;
			else
			{
				int value = s.at(i) - '0';
				if (value > base)
					return false;
			}
		}
		// Base 16
		if (base == 16)
		{
			for (int j = 0; j <= 16; j++)
			{
				if (j == 16)		
					return false;


				if (s.at(i) == arr[j])
					break;
			}
		}

	}




	return true;
}