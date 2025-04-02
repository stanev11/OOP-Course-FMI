#pragma once
#include <iostream>
#include "Duelist.h"

//Constructors
Duelist::Duelist() : deck()
{
	name = new char[100];
}
Duelist::Duelist(const char* name) : deck()
{
	copyName(name);
}
Duelist::Duelist(const char* name,const Deck& deck) : deck(deck)
{
	copyName(name);
}
//Copy Constructor
Duelist::Duelist(const Duelist& other) : deck(other.deck)
{
	copyName(name);
}
//Operator =
Duelist& Duelist::operator=(const Duelist& other)
{
	if (this != &other)
	{
		freeName();
		copyName(other.name);
		this->deck = other.deck;
	}
	return *this;
}
//Destructor
Duelist::~Duelist()
{
	freeName();
}

//Private Functions
void Duelist::freeName()
{
	delete[] this->name;
}
void Duelist::copyName(const char* name)
{
	size_t nameLen = strlen(name);
	this->name = new char[nameLen + 1];
	strcpy_s(this->name, nameLen + 1, name);
}

//Public Functions
int Duelist::numberOfCards()
{
	return this->deck.numberOfCards();
}
int Duelist::numberOfMonsters()
{
	return this->deck.numberOfMonsters();
}

void Duelist::addMagicCard(const MagicCard& card)
{
	return this->deck.addMagicCard(card);
}
void Duelist::addMonster(const Monster& monster)
{
	return this->deck.addMonster(monster);
}

void Duelist::changeMagicCard(size_t index, const MagicCard& other)
{
	this->deck.changeMagicCard(index, other);
}
void Duelist::changeMonster(size_t index, const Monster& other)
{
	this->deck.changeMonster(index, other);
}

void Duelist::removeCard(size_t index)
{
	this->deck.removeCard(index);
}
void Duelist::removeMonster(size_t index)
{
	this->deck.removeMonster(index);
}