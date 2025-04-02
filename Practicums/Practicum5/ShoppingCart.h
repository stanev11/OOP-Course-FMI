#pragma once
#include "Item.h"

class ShoppingCart {
public:
	ShoppingCart();
	ShoppingCart(const Item* items, size_t size);
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart& operator=(const ShoppingCart& other);
	~ShoppingCart();

	void setItems(const Item* items);
	void setSize(size_t size);

	void displayItems() const;
	size_t itemsCount() const;

	void setItem(size_t index, const Item& item);
	void addItem(const Item& item);
	void removeItem(const Item& item);

	bool exists(const Item& item);
	bool isEmpty() const;

	double getPriceOf(const Item& item) const;
	double getTotalPrice() const;

	void sortByName();

	void saveToTextFile(std::ofstream& ofs);
	void saveToBinaryFile(std::ofstream& ofs);

	void readFromTextFile(std::ifstream& ifs);
	void readFromBinaryFile(std::ifstream& ifs);

private:
	Item* items = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void free();
	void copyFrom(const ShoppingCart& other);

	void resize(size_t newCap);
	size_t findIdxOfItem(const Item& item) const;
	void shiftLeft(size_t idx);
};
