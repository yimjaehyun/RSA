

#include "stdafx.h"
// Win32Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;
int main() {

	int dKey;
	int output;
	int answer, answer2;
	string code[] = { " ", ",", ".", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", };


	cout << "Decryption key = ";
	cin >> dKey;
	cout << endl;

	ifstream file;
	file.open("message.txt");
	while (!file.eof())
	{
		file >> output;

		answer2 = output;
		answer = output;
		for (unsigned i = 0; i<dKey - 1; i++)
		{
			answer *= answer2;
			answer = answer % 85;
		}
		if (answer < 2)
			return 1;
		cout << code[answer - 2];

	}
	file.close();
	return 0;
}


