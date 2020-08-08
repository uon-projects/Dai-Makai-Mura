#pragma once

#include "Utils.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class App
{

public:
    App()
    {
        currentScreen = splash;
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

    Event getEvent()
    {
        return event;
    }

    void setEvent(Event eventN)
    {
        event = eventN;
    }

private:
    screen currentScreen;
    Event event;

};