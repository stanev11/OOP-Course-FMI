#pragma once
#include <iostream>
#include "MagicCard.h"
#include "Monster.h"

namespace GLOBAL_CONSTANTS
{
	const size_t MAX_CAPACITY = 20;
}
class Deck
{
	Monster* monsters;
	unsigned monsterCapacity;
	MagicCard* cards;
	unsigned cardsCapacity;

	void copyMonsters(const Monster* monsters);
	void copyCards(const MagicCard* cards);

	void freeMonsters();
	void freeCards();

	void moveCardsLeft(size_t index);
	void moveMonstersLeft(size_t index);
public:
	//Constructors
	Deck();
	Deck(const Monster* monsters, unsigned monsterCap, const MagicCard* cards, unsigned cardsCap);

	//Copy Constructor
	Deck(const Deck& other);

	//Operator=
	Deck& operator=(const Deck& other);

	//Destructor
	~Deck();

	int numberOfCards();
	int numberOfMonsters();

	void addMagicCard(const MagicCard& card);
	void addMonster(const Monster& monster);

	void changeMagicCard(size_t index, const MagicCard& other);
	void changeMonster(size_t index, const Monster& other);

	void removeCard(size_t index);
	void removeMonster(size_t index);

	void sortMagicCards();
	void sortMonsters();
};