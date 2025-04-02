#pragma once
#include <iostream>
#include <fstream>

class Item
{
public:
	Item();
	Item(const char* name, unsigned quantityAvailable, double price);
	Item(const Item& other);

	Item& operator=(const Item& other);
	~Item();

	char* getName() const;
	unsigned getQuantityAvailable() const;
	double getPrice() const;

	void setName(const char* name);
	void setQuantityAvailable(const unsigned price);
	void setPrice(const double price);

	void displayToTextFile(std::ostream& os);
	void readFromTextFile(std::istream& is);

	void writeToBinaryFile(std::ofstream& ofs);
	void readFromBinaryFile(std::ifstream& ifs);

	void display() const;

	int compare(const Item& other);

private:
	char* name;
	unsigned quantityAvailable;
	double price;

	void free();
	void copyFrom(const Item& other);
};