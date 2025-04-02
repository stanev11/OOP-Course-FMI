#pragma once

enum class MagicCardType
{
    trap = 1,
    buff,
    spell
};
class MagicCard {
    char* name;
    char* effect;
    MagicCardType type;

    void copyName(const char* str);
    void copyEffect(const char* str);
    void freeName();
    void freeEffect();

public:
    //Constructors
    MagicCard();
    MagicCard(const char* name, const char* effect, MagicCardType type);

    //Copy Constructor
    MagicCard(const MagicCard& other);

    //Operator=
    MagicCard& operator=(const MagicCard& other);

    //Destructor
    ~MagicCard();

    //Get And Set
    void setName(const char* name);
    void setEffect(const char* effect);
    void setType(const MagicCardType& type);

    char* getName() const;
    char* getEffect() const;
    MagicCardType getCardType() const;
};