#include <iostream>
#include <SFML/Graphics.hpp>

//Compiler Directives
using namespace std;
using namespace sf;

#define WindowX 800
#define WindowY 600

sf::Vector2f TheGameWindow_CurrentDimensions(WindowX,WindowY);
sf::Vector2f TheGameWindow_PerspectiveDimensions(WindowX,WindowY);

sf::RenderWindow TheGameWindow(sf::VideoMode(TheGameWindow_CurrentDimensions.x,TheGameWindow_CurrentDimensions.y),"Dai Makai-Mura");

void InputListener();

int main()
{
	TheGameWindow.setFramerateLimit(60);

	while (TheGameWindow.isOpen())
	{
		InputListener();

		TheGameWindow.clear();



		TheGameWindow.display();
	}

	return 0;
}

void InputListener()
{
//Local Variables
	sf::Event event;

//Main "InputListener()"
	while (TheGameWindow.pollEvent(event))
	{
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
		{
			TheGameWindow.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{

			}
		}
		else if (event.key.code == sf::Keyboard::LControl)
		{

		}
	}
}