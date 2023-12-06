#include "BinToDec.h"

void BinToDec::processFile(std::ifstream& inputFile)
{
    if (!inputFile.is_open())
    {
        std::cout << "There was an error opening the file!" << std::endl;
        return;
    }
}

void BinToDec::convBinToDec(const std::string& filename)
{
    std::ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        std::cout << "There was an error opening the file!" << std::endl;
        return;
    }

 

    std::string binaryNumber;
    while (inputFile >> binaryNumber) // read one binary number at a time
    {
        size_t decimalPointPos = binaryNumber.find('.');

        if (decimalPointPos != std::string::npos)
        {
            // Handle floating-point binary to decimal conversion
            std::bitset<32> integerPart(binaryNumber.substr(0, decimalPointPos));
            std::bitset<32> fractionalPart(binaryNumber.substr(decimalPointPos + 1));

            double decimalNumber = integerPart.to_ulong() + fractionalPart.to_ulong() / pow(2, fractionalPart.size());
            float floatDecimalNumber = static_cast<float>(decimalNumber); // Explicit cast to float
            std::cout << "Float Decimal: " << floatDecimalNumber << "\tBinary: " << binaryNumber << std::endl;
        }
        else
        {
            // Handle integer binary to decimal conversion
            int decimalNumber = std::bitset<32>(binaryNumber).to_ulong();
            float floatDecimalNumber = static_cast<float>(decimalNumber); // Explicit cast to float
            std::cout << "Float Decimal: " << floatDecimalNumber << "\tBinary: " << binaryNumber << std::endl;
        }
    }

    inputFile.close(); // Close the file after processing.
}

void BinToDec::createColumn()
{
    std::cout << "Binary\tDecimal" << std::endl;
}