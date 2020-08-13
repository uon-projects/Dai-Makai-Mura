#pragma once

#include "Utils.h"
#include <SFML/Graphics.hpp>
#include "../../../library/src/header/LoadImage.h"
#include "player/MainCharacter.h"
#include "game/GameMap.h"

using namespace sf;

class App
{

#define WindowX 800
#define WindowY 500

public:
    App()
    {
        currentScreen = splash;
        lvlUnlocked = 1;
        mCharacter = LoadImage().loadSpriteFromTexture("zeoflow_logo", png);
        mMainCharacter = new MainCharacter;
        mGameMap = new GameMap;
    }

    ~App()
    {

    }

public:
    screen getCurrentScreen()
    {
        return currentScreen;
    }

    void setCurrentScreen(screen screenChose)
    {
        currentScreen = screenChose;
        if (screenChose == game)
        {
            mMainCharacter->reset(mLvlSelected);
        }
    }

    int getLevelsUnlocked()
    {
        return lvlUnlocked;
    }

    void setLvl(int mLvl)
    {
        this->mLvlSelected = mLvl;
    }

    int getLvlSelected()
    {
        return mLvlSelected;
    }

    void increaseLevelsUnlocked()
    {
        if (lvlUnlocked < 4)
        {
            lvlUnlocked++;
        }
    }

    Event getEvent()
    {
        return event;
    }

    void setEvent(Event eventN)
    {
        event = eventN;
    }

    Sprite getCharacterSprite()
    {
        return mCharacter;
    }

    MainCharacter *getMainCharacter()
    {
        return mMainCharacter;
    }

    GameMap *getGameMap()
    {
        return mGameMap;
    }

private:
    screen currentScreen;
    Event event;
    int lvlUnlocked;
    Sprite mCharacter;
    MainCharacter *mMainCharacter;
    GameMap *mGameMap;
    int mLvlSelected;

};