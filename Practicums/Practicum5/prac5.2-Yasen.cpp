// prac5.2-Yasen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"

int main()
{
	{
		std::ofstream ofs("newFile.txt",std::ios::binary);
		Item i1("Pesho", 12, 200);
		i1.writeToBinaryFile(ofs);
	}
	{
		std::ifstream ifs("newFile.txt",std::ios::binary);
		Item i1;
		i1.readFromBinaryFile(ifs);
		std::cout << i1.getName() << " " << i1.getQuantityAvailable() << " " << i1.getPrice();
	}
	
}
