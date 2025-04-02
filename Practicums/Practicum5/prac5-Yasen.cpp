// prac5-Yasen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Duelist.h"

int main()
{
	//40 cards = 20 MonsterCards/20 MagicCards
	Deck d;

	// 4-th card in the Monster deck becomes "Blue-eyes white dragon" with
	//ATK: 3000 DEF: 2500
	Monster m("Blue-eyes white dragon", 3000, 2500);
	d.changeMonster(0,m);

	// 5-th card in the Magic deck is added/changed to "Monster reborn"
	MagicCard c("Monster reborn", "revive", MagicCardType::spell);
	d.addMagicCard(c);

	//Returns the amount of MagicCards in the deck
	std::cout<<d.numberOfCards()<<std::endl; //1

	//Returns the amount of MonsterCards in the deck
	std::cout<<d.numberOfMonsters(); //13

	Duelist player1("Seto Kaiba");

	///Changes the 2-nd monster card in the Monster deck to“Dark Magician”
	Monster DarkMagician("Dark Magician", 2500, 2100);
	player1.changeMonster(2, DarkMagician);

	Duelist player2("Yugi Muto");

	//Changes the 2-nd magic card in the Magic deck to “Reflection”
	MagicCard Reflection("Reflection", "Reflects the last played spell", MagicCardType::trap);
	player2.changeMagicCard(2, Reflection);
}
