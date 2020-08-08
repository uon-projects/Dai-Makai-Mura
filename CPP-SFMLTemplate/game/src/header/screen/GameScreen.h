#include <SFML/Graphics.hpp>
#include "../../../../library/src/header/MaterialButton.h"
#include "../App.h"
#include "../player/MainCharacter.h"
#include "../player/EnemyCharacter.h"
#include "../player/EnemyBullet.h"

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

//        window.draw(mApp->getMainCharacter().GetSprite());

    }

    void setApp(App *app)
    {
        this->mApp = app;
    }

    void inputListener(Event event)
    {

        if (event.key.code == sf::Keyboard::Space)
        {
            mApp->getMainCharacter().Jump(750.0f);
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
            mApp->getMainCharacter().Move(-20.0f);
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            mApp->getMainCharacter().Move(20.0f);
        }

    }

    void update(float speed)
    {
        mApp->getMainCharacter().Update(speed);
    }

};
