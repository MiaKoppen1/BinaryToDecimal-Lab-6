#ifndef BINTODEC_H
#define BINTODEC_H

#include <string>
#include <fstream>
#include <iostream>

class BinToDec 
    {
    private:
    //not needed for this program

    public:

    // Static function to convert binary to decimal from a file
    static void convBinToDec(const std::string& filename);
    // Static function to create the column headings
    static void createColumn();
    // Static function to process the binary file and convert to decimal
    static void processFile(std::ifstream& inputFile);

    };

#endif // BINTODEC_H

