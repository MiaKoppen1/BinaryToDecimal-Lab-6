#ifndef BINTODEC
#define BINTODEC
#include <string>
#include <bitset>
#include <fstream>
#include <iostream>

class BinToDec //class created
	{
	private:


	public:
		static void convBinToDec(const std::string& filename);
		void createColumn();
		void processFile(std::ifstream& inputFile);
		
	};

#endif // !BINTODEC
