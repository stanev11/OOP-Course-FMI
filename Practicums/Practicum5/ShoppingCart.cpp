#pragma once
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() : size(16), capacity(2 * size)
{
	items = new Item[size]{};
}
ShoppingCart::ShoppingCart(const Item* items, size_t size)
{
	setSize(size);
	this->capacity = size * 2;
	setItems(items);
}

ShoppingCart::ShoppingCart(const ShoppingCart& other)
{
	copyFrom(other);
}
ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ShoppingCart::~ShoppingCart()
{
	free();
	this->size = this->capacity = 0;
}

void ShoppingCart::free()
{
	delete[] this->items;
}
void ShoppingCart::copyFrom(const ShoppingCart& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->items = new Item[other.size];
	for (size_t i = 0; i < size; i++)
	{
		this->items[i] = other.items[i];
	}
}

void ShoppingCart::setSize(size_t size)
{
	if (size <= 0) return;
	this->size = size;
}
void ShoppingCart::setItems(const Item* items)
{
	if (!items) return;

	this->items = new Item[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		this->items[i] = items[i];
	}
}

void ShoppingCart::displayItems() const
{
	for (size_t i = 0; i < size; i++)
	{
		this->items[i].display();
	}
}
size_t ShoppingCart::itemsCount() const
{
	return this->size;
}

void ShoppingCart::setItem(size_t index,const Item& item)
{
	if (index >= size)
	{
		resize(index + 1);
		this->items[size++] = item;
	}
	else
	{
		this->items[index] = item;
	}
}
void ShoppingCart::addItem(const Item& item)
{
	setItem(size, item);
}
void ShoppingCart::removeItem(const Item& item)
{
	size_t idx = findIdxOfItem(item);
	if (idx == -1) return;

	shiftLeft(idx);
}
size_t ShoppingCart::findIdxOfItem(const Item& item) const
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (!this->items[i].compare(item)) return i;
	}
	return -1;
}
void ShoppingCart::resize(size_t newCap)
{
	this->capacity = newCap;
	Item* newItems = new Item[newCap];
	for (size_t i = 0; i < newCap; i++)
	{
		newItems[i] = this->items[i];
	}
	delete[] items;
	items = newItems;
}
void ShoppingCart::shiftLeft(size_t idx)
{
	size_t i = size - 1;
	while (i > idx)
	{
		this->items[i] = this->items[i - 1];
		i--;
	}
	size-=1;
}
bool ShoppingCart::exists(const Item& item)
{
	if (findIdxOfItem(item) != -1) return true;
	return false;
}

bool ShoppingCart::isEmpty() const
{
	return this->size;
}

double ShoppingCart::getPriceOf(const Item& item) const
{
	size_t idx = findIdxOfItem(item);
	if (idx == -1) return 0;
	return items[idx].getPrice();
}

double ShoppingCart::getTotalPrice() const
{
	double res = 0;
	for (size_t i = 0; i < size; i++)
	{
		res += items[i].getPrice();
	}
	return res;
}

void ShoppingCart::sortByName()
{
	
}

void ShoppingCart::saveToTextFile(std::ofstream& ofs)
{
	if (!ofs.is_open()) return;
	ofs << size << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		items[i].displayToTextFile(ofs);
	}
}

void ShoppingCart::saveToBinaryFile(std::ofstream& ofs)
{
	if (!ofs.is_open()) return;
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		items[i].writeToBinaryFile(ofs);
	}
}

void ShoppingCart::readFromTextFile(std::ifstream& ifs)
{
	if (!ifs.is_open()) return;
	size_t size;
	ifs >> size;
	items = new Item[size];
	for (size_t i = 0; i < size; i++)
	{
		items[i].readFromTextFile(ifs);
	}
}

void ShoppingCart::readFromBinaryFile(std::ifstream& ifs)
{
	if (!ifs.is_open()) return;
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	items = new Item[size];
	for (size_t i = 0; i < size; i++)
	{
		items[i].readFromBinaryFile(ifs);
	}
}
