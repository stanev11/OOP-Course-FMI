
#include <iostream>
#include "Monster.h"

//Private Funcs
void Monster::copyName(const char* name)
{
    size_t nameLen = strlen(name);
    this->name = new char[nameLen + 1];
    strcpy_s(this->name, nameLen + 1, name);
 }
void Monster::freeName()
{
    if(!name)
    delete[] this->name;
}

//Constructors
Monster::Monster() : name(), attackPoints(0),defensePoints(0) {
    name = new char[100];
}
Monster::Monster(const char* name, unsigned attackP, unsigned defenseP) : attackPoints(attackP), defensePoints(defenseP)
{
    copyName(name);
}
//Copy Constructor
Monster::Monster(const Monster& other) : attackPoints(other.attackPoints), defensePoints(other.defensePoints)
{
    copyName(other.name);
}

//Operator =
Monster& Monster::operator=(const Monster& other)
{
    if (this != &other)
    {
        freeName();
        copyName(other.name);

        this->attackPoints = other.attackPoints;
        this->defensePoints = other.defensePoints;
    }
    return *this;
}

//Destructor
Monster::~Monster()
{
    freeName();
}

//Get And Set
void Monster::setName(const char* name)
{
    if (!name) return;
    copyName(name);
}
void Monster::setDefensePoints(const unsigned defenseP)
{
    if (defenseP < 0) return;
    this->defensePoints = defenseP;
}
void Monster::setAttackPoints(const unsigned attackP)
{
    if (attackP < 0) return;
    this->attackPoints = attackP;
}

char* Monster::getName() const
{
    return this->name;
}
unsigned Monster::getAttackPoints() const
{
    return this->attackPoints;
}
unsigned Monster::getDefensePoints() const
{
    return this->defensePoints;
}