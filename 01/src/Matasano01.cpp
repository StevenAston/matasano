//============================================================================
// Name        : Matasano01.cpp
// Author      : Steven Aston
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X','Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x', 'y', 'z', '0', '1', '2', '3','4', '5', '6', '7', '8', '9', '+', '/'};

int hexToInt (char i) {
	switch (i)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'a': return 10;
		case 'b': return 11;
		case 'c': return 12;
		case 'd': return 13;
		case 'e': return 14;
		case 'f': return 15;
	}
	return 0;
}

string decToBin(unsigned n)
{
    const size_t size = sizeof(n) * 8;
    char result[size];
    unsigned index = size;
    do {result[--index] = '0' + (n & 1);}
    while (n >>= 1);
    return std::string(result + index, result + size);
}

int binToInt(string input)
{
	int i = 0;
	int total = 0;
	string reversed = string(input.rbegin(), input.rend());
	while (i <= input.length()) {
		if (reversed[i] == '1') {
			total = total + pow(2,i);
		}
		++i;
	}
	return total;
}

string binaryPadding (string input) {
	while (input.length() != 4) {
		input.insert(0, "0");
	}
	return input;
}

string encodeBase64 (string binary) {
	string chunk;
	string output;
	int i = 0;
	while (i < binary.length()) {
		for (int a = 0; a < 6; a++) {
			chunk += (binary[i+a]);
		}
		i+=6;
		output += encoding_table[binToInt(chunk)];
		chunk = "";
	}
	return output;
}

string hexToBase64 (string hex) {
	int stringSize = hex.length();
	int intConversion[stringSize];
	std::vector<string> binConversion(stringSize);
	string binString;
	int counter = 0;

	while (counter < hex.length()) {
		intConversion[counter] = hexToInt(hex[counter]);
		binConversion[counter] = binaryPadding(decToBin(intConversion[counter]));
		binString += binaryPadding(decToBin(intConversion[counter]));
		++counter;
	}
	return encodeBase64(binString);
}

int main() {
	//string input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

	string input;
	cout << "Enter what you'd like to base64.\n";
	cin >> input;
	cout << hexToBase64(input) << "\n\n";
}
