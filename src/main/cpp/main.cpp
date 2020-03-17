#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define WindowX 800
#define WindowY 500

Vector2f theGameWindow_currentDimensions(WindowX, WindowY); // NOLINT(cert-err58-cpp)
Vector2f theGameWindow_perspectiveDimensions(WindowX, WindowY); // NOLINT(cert-err58-cpp)
RenderWindow theGameWindow( // NOLINT(cert-err58-cpp)
        VideoMode(theGameWindow_currentDimensions.x, theGameWindow_currentDimensions.y),
        "Dai Makai-Mura");

void init();

void inputListener();

void update(float seconds);

void draw();

int main()
{
    Clock clockTime;
    Time speed;

    theGameWindow.setFramerateLimit(60);
    init();

    while (theGameWindow.isOpen())
    {
        inputListener();

        speed = clockTime.restart();
        update(speed.asSeconds());

        theGameWindow.clear();

        draw();

        theGameWindow.display();
    }

    return 0;
}

void init()
{
    Event event{};

    while (theGameWindow.pollEvent(event))
    {
        if (event.key.code == Keyboard::Escape || event.type == Event::Closed)
        {
            theGameWindow.close();
        }
    }

}

void inputListener()
{

}

void update(float seconds)
{

}

void draw()
{

}
