//============================================================================
// Name        : Matasano02.cpp
// Author      : Steven Aston
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

string decimalToBinary (int input)
{
	string output = "0000";
	if (input >= 8)
	{
		input-=8;
		output[0]='1';
	}
	if (input >= 4)
	{
		input-=4;
		output[1]='1';
	}
	if (input >= 2)
	{
		input-=2;
		output[2]='1';
	}
	if (input >= 1)
	{
		input-=1;
		output[3]='1';
	}
	return output;
}

int binaryToDecimal (string input)
{
	int output = 0;
	if (input[0] == '1')
	{
		output=8;
	}
	if (input[1] == '1')
	{
		output+=4;
	}
	if (input[2] == '1')
	{
		output+=2;
	}
	if (input[3] == '1')
	{
		output+=1;
	}
	return output;
}

char decimalToHex (int input)  // Convert a single decimal number to hex (only accepts 0-15)
{
	switch (input)
	{
		case 0: return '0'; break;
		case 1: return '1'; break;
		case 2: return '2'; break;
		case 3: return '3'; break;
		case 4: return '4'; break;
		case 5: return '5'; break;
		case 6: return '6'; break;
		case 7: return '7'; break;
		case 8: return '8'; break;
		case 9: return '9'; break;
		case 10: return 'a'; break;
		case 11: return 'b'; break;
		case 12: return 'c'; break;
		case 13: return 'd'; break;
		case 14: return 'e'; break;
		case 15: return 'f'; break;
	}
	cout << "Error converting Decimal to Hex.";
	return -1;
}

int hexToDecimal (char input)  // Convert a single decimal digit to hex (only accepts 0-15)
{
	switch (input)
	{
		case '0': return 0; break;
		case '1': return 1; break;
		case '2': return 2; break;
		case '3': return 3; break;
		case '4': return 4; break;
		case '5': return 5; break;
		case '6': return 6; break;
		case '7': return 7; break;
		case '8': return 8; break;
		case '9': return 9; break;
		case 'a': return 10; break;
		case 'b': return 11; break;
		case 'c': return 12; break;
		case 'd': return 13; break;
		case 'e': return 14; break;
		case 'f': return 15; break;
	}
	cout << "Error encountered converting hex to decimal.";
	return -1;  // Return error value
}

string xorFourBitBinary (string input1, string input2)
{
	string output = "0000";
	bool a;
	bool b;
	for (int n=0; n<4; n++)
	{
		if (input1[n] == '0')
		{
			a = false;
		} else {
			a = true;
		}
		if (input2[n] == '0')
		{
			b = false;
		} else {
			b = true;
		}
		if ((a ^ b) == false)
		{
			output[n] = '0';
		} else {
			output[n] = '1';
		}
	}
	return output;
}

int main() {
	string seedNum = "1c0111001f010100061a024b53535009181c";
	string xorNum = "686974207468652062756c6c277320657965";
	int intContainer;
	string binaryContainer;
	string xorOutput;

	vector<string> seedBinary(seedNum.length());
	vector<string> xorBinary(seedNum.length());
	vector<string> resultBinary(seedNum.length());

	for (int i = 0; i < seedNum.length(); i++)
	{
		// convert original number to binary
		intContainer = hexToDecimal(seedNum[i]);
		binaryContainer = decimalToBinary(intContainer);
		seedBinary[i] = binaryContainer;

		// convert xor number to binary
		intContainer = hexToDecimal(xorNum[i]);
		binaryContainer = decimalToBinary(intContainer);
		xorBinary[i] = binaryContainer;

		// XOR results
		resultBinary[i] = xorFourBitBinary(seedBinary[i], xorBinary[i]);

		cout << seedNum[i] << "\t" << hexToDecimal(seedNum[i]) << "\t" << seedBinary[i] << "\t|\t" << xorNum[i] << "\t" << hexToDecimal(xorNum[i]) << "\t" << xorBinary[i] << "\t| xor\t" << resultBinary[i] << "\t" << binaryToDecimal(resultBinary[i]) << "\t" << decimalToHex(binaryToDecimal(resultBinary[i])) << "\n";
		xorOutput += decimalToHex(binaryToDecimal(resultBinary[i]));

	}
	cout << "\n\n" << seedNum << "\nxor\n" << xorNum << "\n=\n" << xorOutput;
}
