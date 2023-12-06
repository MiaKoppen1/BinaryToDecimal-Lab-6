/*
Mia Koppen
3rd semester, 1st year
Due: December 3rd
Lab #6
Description: Write a C++ program that reads characters representing binary (base 2)
numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
numbers. The binary and decimal numbers should be output in two columns with
appropriate headings.
There is only one binary number per input line, but an arbitrary number of blanks can
precede the number. The program must read the binary numbers one character at a
time. As each character is read, the program multiplies the total decimal value by 2 and
adds either a 1 or 0, depending on the input character. The program should check for
bad data; if it encounters anything except a 1 or 0, it should output the message “Bad
digit on input.” The maximum number of spaces that could exist between any two digits
of a binary number in the input file will be one, in which case, the binary digit would be
considered bad. The output for this program should be to the screen and not an output
file. In order to read in one character at a time, you will need to use the cin.get
command. When you have completed this lab, upload a copy of the .cpp file called
Lab6.cpp and BinaryIn.dat to GitHub. Make sure to use classes and proper comments
and coding technique
*/
#include "BinToDec.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

int main()
	{

	BinToDec binaryToDecimal; //object created 

	const std::string filename = "C:/Users/KOPPEN11/Desktop/C++/Lab #6/BinaryIn.dat"; //naming the input file & opening the input file
	std::ifstream inputFile(filename);

	//check if the file is opened, if not, outputs a message (in  red) saying there was an error opening the file.
	if (!inputFile.is_open())
		{
		std::cout << "\133[1;31mThere Was An Error Opening The File :( \033[0m" << filename << std::endl;
		}
	else //if the file opens succesffuly, outputs a message (in green) saying the file was opened succesfully.
		{
		std::cout << filename << "   " << "\033[32;1mWas Opened Successfully :)\033[0m" << std::endl;
		std::cout << std::endl;
		binaryToDecimal.processFile(inputFile);
		binaryToDecimal.convBinToDec(filename);
		binaryToDecimal.createColumn();

		inputFile.close();
		}
	return 0;
	}