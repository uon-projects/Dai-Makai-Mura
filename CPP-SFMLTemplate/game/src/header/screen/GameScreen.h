#include <SFML/Graphics.hpp>
#include "../../../../library/src/header/MaterialButton.h"
#include "../App.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class GameScreen
{

public:
    RectangleShape gameMenuScreenBackground;
    App *mApp;

public:
    GameScreen()
    {

        gameMenuScreenBackground.setFillColor(Color(0, 150, 136));

    }

    ~GameScreen()
    {

    }

public:
    void draw(RenderWindow &window)
    {

        gameMenuScreenBackground.setSize(Vector2f((float) window.getSize().x, (float) window.getSize().y));
        window.draw(gameMenuScreenBackground);

        window.draw(mApp->getMainCharacter().getSprite());

    }

    void setApp(App *app)
    {
        this->mApp = app;
    }

    void inputListener(Event event)
    {
        if (event.key.code == Keyboard::Left || event.key.code == Keyboard::A)
        {
            cout << "left\n";
        } else if (event.key.code == Keyboard::Right || event.key.code == Keyboard::D)
        {
            cout << "right\n";
        } else if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)
        {
            cout << "up\n";
        } else if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)
        {
            cout << "down\n";
		} else if (event.key.code == Keyboard::Num1 || event.key.code == Keyboard::Numpad1)
        {
            cout << "1\n";
        } else if (event.key.code == Keyboard::Num2 || event.key.code == Keyboard::Numpad2)
        {
            cout << "2\n";
        } else if (event.key.code == Keyboard::Num3 || event.key.code == Keyboard::Numpad3)
        {
            cout << "3\n";
        } else if (event.key.code == Keyboard::Space)
        {
            cout << "space\n";
        }
    }

    void update(float speed)
    {



    }

};
