#pragma once

class Monster {
    char* name;
    unsigned attackPoints;
    unsigned defensePoints;

    void copyName(const char* name);
    void freeName();

public:
    //Constructors
    Monster();
    Monster(const char* name, unsigned attackP, unsigned defenseP);

    //Copy Constructor
    Monster(const Monster& other);

    //Operator =
    Monster& operator=(const Monster& other);

    //Destructor
    ~Monster();
   
    //Get And Set
    void setName(const char* name);
    void setAttackPoints(const unsigned attackP);
    void setDefensePoints(const unsigned defenseP);

    char* getName() const;
    unsigned getAttackPoints() const;
    unsigned getDefensePoints() const;
};