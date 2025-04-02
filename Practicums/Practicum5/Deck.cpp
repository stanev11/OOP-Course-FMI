#pragma once
#include "Deck.h"

//Private Funcs
void Deck::copyMonsters(const Monster* monsters)
{
	this->monsters = new Monster[monsterCapacity];
	for (int i = 0; i < monsterCapacity; i++)
	{
		this->monsters[i] =monsters[i];
	}
}
void Deck::copyCards(const MagicCard* cards)
{
	this->cards = new MagicCard[cardsCapacity];
	for (int i = 0; i < cardsCapacity; i++)
	{
		this->cards[i] = cards[i];
	}
}

void Deck::freeMonsters()
{
	delete[] this->monsters;
}
void Deck::freeCards()
{
	delete[] this->cards;
}

void Deck::moveCardsLeft(size_t index)
{
	while (index <= this->cardsCapacity)
	{
		this->cards[index] = this->cards[index + 1];
		index++;
	}
}
void Deck::moveMonstersLeft(size_t index)
{
	while (index <= this->monsterCapacity)
	{
		this->monsters[index] = this->monsters[index + 1];
		index++;
	}
}

//Constructors
Deck::Deck() : monsters(), monsterCapacity(0), cards(), cardsCapacity(0){
	monsters = new Monster[20];
	cards = new MagicCard[20];
}
Deck::Deck(const Monster* monsters, unsigned monsterCap, const MagicCard* cards, unsigned cardsCap)
	:monsterCapacity(monsterCap),cardsCapacity(cardsCap)
{
	this->monsters = new Monster[monsterCapacity];
	for (int i = 0; i < monsterCapacity; i++)
	{
		this->monsters[i] = monsters[i];
	}

	this->cards = new MagicCard[cardsCapacity];
	for (int i = 0; i < cardsCapacity; i++)
	{
		this->cards[i] = cards[i];
	}
}
//Copy Constructor
Deck::Deck(const Deck& other) : monsterCapacity(other.monsterCapacity), cardsCapacity(other.cardsCapacity)
{
	copyMonsters(other.monsters);
	copyCards(other.cards);
}
//Operator =
Deck& Deck::operator=(const Deck& other)
{
	if (this != &other)
	{
		freeMonsters();
		freeCards();

		this->monsterCapacity = other.monsterCapacity;
		this->cardsCapacity = other.cardsCapacity;

		copyMonsters(other.monsters);
		copyCards(other.cards);
	}
	return *this;
}
//Destructor
Deck::~Deck()
{
	freeMonsters();
	freeCards();
}

//Public Funcs
int Deck::numberOfCards()
{
	return this->cardsCapacity;
}
int Deck::numberOfMonsters()
{
	return this->monsterCapacity;
}

void Deck::addMagicCard(const MagicCard& card)
{
	if (cardsCapacity < GLOBAL_CONSTANTS::MAX_CAPACITY)
	{
		this->cards[cardsCapacity++] = card;
	}
	else
	{
		std::cout << "There is no space for more magic cards in this deck!" << std::endl;
	}
}
void Deck::addMonster(const Monster& monster)
{
	if (cardsCapacity < GLOBAL_CONSTANTS::MAX_CAPACITY)
	{
		this->monsters[monsterCapacity++] = monster;
	}
	else
	{
		std::cout << "There is no space for more monsters in this deck!" << std::endl;
	}
}

void Deck::changeMagicCard(size_t index, const MagicCard& other)
{
	if (index<0 || index>=this->cardsCapacity) return;
	this->cards[index] = other;
}
void Deck::changeMonster(size_t index, const Monster& other)
{
	if (index<0 || index>=this->monsterCapacity) return;
	this->monsters[index] = other;
}

void Deck::removeCard(size_t index)
{
	if (index < 0 || index >= this->cardsCapacity) return;
	moveCardsLeft(index);
	cardsCapacity--;
}
void Deck::removeMonster(size_t index)
{
	if (index < 0 || index >= this->monsterCapacity) return;
	moveMonstersLeft(index);
	monsterCapacity--;
}

void Deck::sortMagicCards()
{

}
void Deck::sortMonsters()
{

}