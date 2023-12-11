/*
Mia Koppen
3rd semester, 1st year
Due: December 3rd
Lab #6
Description: Write a C++ program that reads characters representing binary (base 2)
numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
numbers. The binary and decimal numbers should be output in two columns.The program multiplies the total decimal value by 2 and
adds either a 1 or 0. If it encounters anything except a 1 or 0, it should output the message “Bad
digit on input.” Use the cin.get
command. 
*/

#include "BinToDec.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
	{
	BinToDec binaryToDecimal; //object created / Created an instance of the BinToDec class
	const std::string filename = "C:/Users/KOPPEN11/Desktop/C++/Lab #6/BinaryIn.dat"; // Define the filename for the input binary file

	std::ifstream inputFile(filename); // Open the input file

	//check if the file is opened, if not, outputs an error message in red if the file opening fails
	if (!inputFile.is_open())
		{
		std::cout << "\133[1;31mThere Was An Error Opening The File :( \033[0m" << filename << std::endl;
		}
	else // Outputs a success message in green if the file is opened successfully
		{
		std::cout << filename << "   " << "\033[32;1mWas Opened Successfully :)\033[0m" << std::endl;
		std::cout << std::endl;
		}

		// Process the binary file using the BinToDec class
		binaryToDecimal.processFile(inputFile);
		// Convert binary to decimal using the BinToDec class
		binaryToDecimal.convBinToDec(filename);

	return 0; // Return 0 to indicate successful execution

	}
