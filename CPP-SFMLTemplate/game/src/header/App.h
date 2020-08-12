#pragma once

#include "Utils.h"
#include <SFML/Graphics.hpp>
#include "../../../library/src/header/LoadImage.h"

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

private:
    screen currentScreen;
    Event event;
    int lvlUnlocked;
    Sprite mCharacter;

};