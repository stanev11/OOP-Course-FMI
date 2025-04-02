#pragma once
#include <iostream>
#include "MagicCard.h"

//Private Func
void MagicCard::copyName(const char* str)
{
	size_t strLen = strlen(str);
	this->name = new char[strLen + 1];
	strcpy_s(this->name, strLen + 1, str);
}
void MagicCard::copyEffect(const char* str)
{
	size_t strLen = strlen(str);
	this->effect = new char[strLen + 1];
	strcpy_s(this->effect, strLen + 1, str);
}

void MagicCard::freeName()
{
	delete[] this->name;
}
void MagicCard::freeEffect()
{
	delete[] this->effect;
}

//Constructors
MagicCard::MagicCard() : name(), effect(), type(){
	name = new char[100];
	effect = new char[100];
	type = MagicCardType::trap;
}
MagicCard::MagicCard(const char* name, const char* effect, MagicCardType type) : type(type)
{
	copyName(name);
	copyEffect(effect);
}

//Copy Constructor
MagicCard::MagicCard(const MagicCard& other) : type(other.type)
{
	copyName(other.name);
	copyEffect(other.effect);
}

//Operator =
MagicCard& MagicCard::operator=(const MagicCard& other)
{
	if (this != &other)
	{
		delete[] this->name;
		copyName(other.name);
		
		delete[] this->effect;
		copyEffect(other.effect);

		this->type = other.type;
	}
	return *this;
}

//Destructor
MagicCard::~MagicCard()
{
	freeName();
	freeEffect();
}

//Get And Set
void MagicCard::setName(const char* name)
{
	if (!name || strlen(name)>25) return;
	copyName(name);
}
void MagicCard::setEffect(const char* effect)
{
	if (!effect || strlen(effect)>100) return;
	copyEffect(effect);
}
void MagicCard::setType(const MagicCardType& type)
{
	this->type = type;
}

char* MagicCard::getName() const
{
	return this->name;
}
char* MagicCard::getEffect() const
{
	return this->effect;
}
MagicCardType MagicCard::getCardType() const
{
	return this->type;
}