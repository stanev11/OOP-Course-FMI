#include "Item.h"

Item::Item() : name(nullptr),quantityAvailable(0),price(0) {}
Item::Item(const char* name, unsigned quantityAvailable, double price)
{
	setName(name);
	setQuantityAvailable(quantityAvailable);
	setPrice(price);
}

Item::Item(const Item& other)
{
	copyFrom(other);
}
Item& Item::operator=(const Item& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Item::~Item()
{
	free();
	this->quantityAvailable = 0;
	this->price = 0;
}

void Item::setName(const char* name)
{
	if (!name || strlen(name) == 0) return;

	delete[] this->name;
	size_t nameLen = strlen(name) + 1;
	this->name = new char[nameLen];
	strcpy_s(this->name, nameLen, name);
}
void Item::setQuantityAvailable(const unsigned quantityAvailable)
{
	if (quantityAvailable < 0) return;
	this->quantityAvailable = quantityAvailable;
}
void Item::setPrice(const double price)
{
	if (price < 0) return;
	this->price = price;
}

void Item::free()
{
	delete[] this->name;
	this->quantityAvailable = 0;
	this->price = 0;
}

void Item::copyFrom(const Item& other)
{
	size_t nameLen = strlen(other.name)+1;
	this->name = new char[nameLen];
	strcpy_s(this->name, nameLen, other.name);

	this->quantityAvailable = other.quantityAvailable;
	this->price = other.price;
}

char* Item::getName() const
{
	return this->name;
}
unsigned Item::getQuantityAvailable() const
{
	return this->quantityAvailable;
}
double Item::getPrice() const
{
	return this->price;
}

void Item::displayToTextFile(std::ostream& os)
{
	size_t nameLen = strlen(this->name)+1;
	os << nameLen << " " << this->name << " " << this->quantityAvailable << " " << this->price << std::endl;
}
void Item::readFromTextFile(std::istream& is)
{
	size_t nameLen;
	is >> nameLen;
	this->name = new char[nameLen];
	is >> this->name;
	is >> this->quantityAvailable >> this->price;
}

void Item::writeToBinaryFile(std::ofstream& ofs)
{
	size_t nameLen = strlen(this->name)+1;
	ofs.write((const char*)&nameLen, sizeof(nameLen));
	ofs.write((const char*)name, nameLen);
	ofs.write((const char*)&quantityAvailable, sizeof(quantityAvailable));
	ofs.write((const char*)&price, sizeof(price));
}
void Item::readFromBinaryFile(std::ifstream& ifs)
{
	size_t nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));
	this->name = new char[nameLen];
	ifs.read((char*)name, nameLen);
	ifs.read((char*)&quantityAvailable, sizeof(quantityAvailable));
	ifs.read((char*)&price, sizeof(price));
}

void Item::display() const
{
	std::cout << this->name << " " << this->quantityAvailable << " " << this->price << std::endl;
}

int Item::compare(const Item& other)
{
	return strcmp(this->name, other.name);
}