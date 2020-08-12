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

    }

    void setApp(App *app)
    {
        this->mApp = app;
    }

    void inputListener(Event event)
    {
        cout<<"inputListener: GameScreen "<<event.key.code<<'\n';
    }

    void update(float speed)
    {

    }

};
