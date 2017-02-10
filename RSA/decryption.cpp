#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <ctype.h>
using namespace std;
int main() {
	bool run = true;
	//0     1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18  19   20   21    22  23    24   25   26   27   28
	char code[] = { ' ', ',', '.', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' }; \
	char code2[] = { ' ', ',', '.', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };


	int choice;
	cout << "1. Encrypt a message" << endl;
	cout << "2. Decrypt a message" << endl;
	cout << "3. Quit " << endl;
	cout << "Enter number: ";
	cin >> choice;
	if (choice == 1)
	{
		string message;
		cout << "enter message: ";
		cin >> message;

		ofstream file;
		file.open("message.txt");

		for (unsigned i = 0; i < message.size(); i++)
		{
			for (unsigned j = 0; j < sizeof(code); j++)
			{
				char letter = message[i];
				if (letter == code[j])
				{
					file << j + 2 << " ";
				}
			}
		}
	}
	else if (choice == 2)
	{
		int dKey;
		int output;
		int answer, answer2;


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
			for (unsigned i = 0; i < dKey - 1; i++)
			{
				answer *= answer2;
				answer = answer % 85;
			}
			if (answer < 2)
				return 1;
			cout << code[answer - 2];

		}
		file.close();
	}
}


