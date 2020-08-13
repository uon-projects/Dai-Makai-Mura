#ifndef DAI_MAKAI_MURA_NPCHARACTER_H
#define DAI_MAKAI_MURA_NPCHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../game/GameMap.h"

using namespace std;
using namespace sf;

class NPCharacter
{

private:
    GameMap *mGameMap;

public:
    NPCharacter()
    {

    }

    ~NPCharacter()
    {

    }

    void setGameMap(GameMap *mGameMap)
    {
        this->mGameMap = mGameMap;
    }

};

#endif //DAI_MAKAI_MURA_NPCHARACTER_H
