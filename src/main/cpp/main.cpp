#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define WindowX 800
#define WindowY 500

Vector2f TheGameWindow_CurrentDimensions(WindowX,WindowY);
Vector2f TheGameWindow_PerspectiveDimensions(WindowX,WindowY);
RenderWindow TheGameWindow(sf::VideoMode(TheGameWindow_CurrentDimensions.x,TheGameWindow_CurrentDimensions.y),"Dai Makai-Mura");

void Init();
void InputListener();
void Update(float seconds);
void Draw();

int main()
{
    Clock ClockTime;
    Time Speed;

    TheGameWindow.setFramerateLimit(60);
    Init();

    while (TheGameWindow.isOpen())
    {
        InputListener();

        Speed = ClockTime.restart();
        Update(Speed.asSeconds());

        TheGameWindow.clear();

        Draw();

        TheGameWindow.display();
    }

    return 0;
}

void Init()
{

}

void InputListener()
{

}

void Update(float seconds)
{

}

void Draw() {

}
