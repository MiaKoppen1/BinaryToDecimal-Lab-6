
#include "BinToDec.h"

void BinToDec::createColumn() 
    {
    // Output column headings;Binary numbers under the blue header, decimals under the purple header.
    std::cout << "\033[4m\033[34;1mBinary\033[0m\033[35;1m\t\033[4mDecimal\033[0m" << std::endl; 
    }

void BinToDec::processFile(std::ifstream& inputFile) 
    {
    createColumn(); // Call static function directly to create column headings

    char binaryDigit;
    std::string binaryNumber;

        // Read characters from the input file one by one
 while (inputFile.get(binaryDigit)) 
        {
        // Check if the character is a binary digit
        if (binaryDigit == '0' || binaryDigit == '1') 
            {
            binaryNumber += binaryDigit;
            }
        // Check for bad characters that are not '0', '1', ' ', or '\n'
        else if (binaryDigit != ' ' && binaryDigit != '\n') 
            {
            std::cerr << "Bad digit on input." << std::endl; 
            return; // Exit the function if bad digit is encountered
            }

        // Check if a complete binary number is formed
        else if (!binaryNumber.empty())
            {
            double decimalNumber = 0.0; // Initialize decimal value for the current binary number

            // Convert binary to decimal and output the result
            for (char digit : binaryNumber)
                {
                decimalNumber *= 2.0; // Shift the decimal value left by one position
                decimalNumber += (digit - '0'); // Convert char to int and add to decimal value
                }
            std::cout << binaryNumber << "\t" << decimalNumber << std::endl;

            binaryNumber.clear(); // Reset for the next binary number
             }
        }

 // Check for any remaining binary number at the end of the file
 if (!binaryNumber.empty()) 
    {
    std::cerr << "Incomplete binary number at the end of the file." << std::endl;
    }

    }

void BinToDec::convBinToDec(const std::string& filename) 
    {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) 
        {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return; // Exit the function if file opening fails
        } 
    inputFile.close(); // Close the file after processing.
    }
       
