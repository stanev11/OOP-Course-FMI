#pragma once
#include <iostream>
#include "Deck.h"

class Duelist {
	char* name;
	Deck deck;

	void copyName(const char* name);
	void freeName();
public:
	Duelist();
	Duelist(const char* name);
	Duelist(const char* name,const Deck& deck);

	//Copy Constructor
	Duelist(const Duelist& other);

	//Operator =
	Duelist& operator=(const Duelist& other);

	//Destructor
	~Duelist();

	int numberOfCards();
	int numberOfMonsters();

	void addMagicCard(const MagicCard& card);
	void addMonster(const Monster& monster);

	void changeMagicCard(size_t index, const MagicCard& other);
	void changeMonster(size_t index, const Monster& other);

	void removeCard(size_t index);
	void removeMonster(size_t index);

};