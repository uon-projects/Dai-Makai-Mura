#include <SFML/Graphics.hpp>
#include "../../../../library/src/header/MaterialButton.h"
#include "../App.h"
#include "../player/MainCharacter.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class GameScreen
{

private:
    RectangleShape gameMenuScreenBackground;
    App *mApp;
    MainCharacter *mMainCharacter;

public:
    GameScreen()
    {

        gameMenuScreenBackground.setFillColor(Color(105, 89, 4));

    }

    ~GameScreen()
    {

    }

public:
    void draw(RenderWindow &window)
    {

        gameMenuScreenBackground.setSize(Vector2f((float) window.getSize().x, (float) window.getSize().y));
        window.draw(gameMenuScreenBackground);

        window.draw(mMainCharacter->getSprite());

    }

    void setApp(App *app)
    {
        this->mApp = app;
        mMainCharacter = mApp->getMainCharacter();
    }

    void inputListener(Event event)
    {
        if (event.key.code == Keyboard::Space)
        {
            mMainCharacter->jump(650.0f);
        }
        if (event.key.code == Keyboard::Left || event.key.code == Keyboard::A)
        {
            mMainCharacter->move(-20.0f);
        } else if (event.key.code == Keyboard::Right || event.key.code == Keyboard::D)
        {
            mMainCharacter->move(20.0f);
        } /*else if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)
        {
            cout << "up\n";
        } else if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)
        {
            cout << "down\n";
		} */
        if (event.key.code == Keyboard::Num1 || event.key.code == Keyboard::Numpad1)
        {
            cout << "1\n";
        } else if (event.key.code == Keyboard::Num2 || event.key.code == Keyboard::Numpad2)
        {
            cout << "2\n";
        } else if (event.key.code == Keyboard::Num3 || event.key.code == Keyboard::Numpad3)
        {
            cout << "3\n";
        }
    }

    void update(float speed)
    {

        mMainCharacter->update(speed);

    }

};
