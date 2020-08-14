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
        mLoadImage = new LoadImage();
        currentScreen = splash;
        lvlUnlocked = 1;
        mCharacter = mLoadImage->loadSpriteFromTexture("zeoflow_logo", png);
        mMainCharacter = new MainCharacter;
        mGameMap = new GameMap;
        mNewGameLvl = false;
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
            mNewGameLvl = true;
            mMainCharacter->reset(mLvlSelected);
        }
    }

    int getLevelsUnlocked()
    {
        return lvlUnlocked;
    }

    void increaseLevelsUnlocked()
    {
        if (lvlUnlocked < 4)
        {
            lvlUnlocked++;
        }
    }

    bool isNewGame()
    {
        bool isNewGame = mNewGameLvl;
        if(mNewGameLvl)
        {
            mNewGameLvl = false;
        }
        return isNewGame;
    }

    void setLvl(int mLvl)
    {
        this->mLvlSelected = mLvl;
    }

    int getLvlSelected()
    {
        return mLvlSelected;
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

    Sprite getFireSprite()
    {
        return mLoadImage->loadSpriteFromTexture("fire1", png);
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
    LoadImage *mLoadImage;
    int mLvlSelected;
    int mCharacterLives;
    bool mNewGameLvl;

};