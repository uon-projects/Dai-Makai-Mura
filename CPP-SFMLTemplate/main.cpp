#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "MainCharacter.h"
#include "EnemyCharacter.h"
#include "EnemyBullet.h"

//Compiler Directives
using namespace std;
using namespace sf;

#define WindowX 800
#define WindowY 500

Vector2f TheGameWindow_CurrentDimensions(WindowX,WindowY);
Vector2f TheGameWindow_PerspectiveDimensions(WindowX,WindowY);
RenderWindow TheGameWindow(sf::VideoMode(TheGameWindow_CurrentDimensions.x,TheGameWindow_CurrentDimensions.y),"Dai Makai-Mura");

MainCharacter GameCharacter;
vector<EnemyCharacter*> EnemyCharacters;
vector<EnemyBullet*> EnemyBullets;
Texture BackgroundTexture;
Sprite BackgroundSprite;
float CurrentTime, PreviousTime = 0.0f;

void Init();
void InputListener();
void Draw();
void Update(float);
void SpawnEnemy();
void ShootBullets(int);

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

	if (!BackgroundTexture.loadFromFile("Assets/Background.png"))
	{
		cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	BackgroundSprite.setTexture(BackgroundTexture);

	GameCharacter.Init("Assets/main_character_vector.png",sf::Vector2f(TheGameWindow_CurrentDimensions.x * 0.25f, TheGameWindow_CurrentDimensions.y * 0.5f), 200);
	srand((int)time(0));

}

void InputListener()
{
	sf::Event event;

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
				GameCharacter.Jump(750.0f);
			}
		}
		else if (event.key.code == sf::Keyboard::Num1)
		{
			ShootBullets(1);
		}
		else if (event.key.code == sf::Keyboard::Num2)
		{
			ShootBullets(2);
		}
		else if (event.key.code == sf::Keyboard::Left)
		{
			GameCharacter.Move(-20.0f);
		}
		else if (event.key.code == sf::Keyboard::Right)
		{
			GameCharacter.Move(20.0f);
		}
	}
}

void Draw()
{

	TheGameWindow.draw(BackgroundSprite);
	TheGameWindow.draw(GameCharacter.GetSprite());
	for (EnemyCharacter *Enemy : EnemyCharacters)
	{
		TheGameWindow.draw(Enemy -> GetSprite());
	}
	for (EnemyBullet *Bullet : EnemyBullets)
	{
		TheGameWindow.draw(Bullet -> GetSprite());
	}

}

void Update(float Speed)
{
	int i, j;

	GameCharacter.Update(Speed);
	CurrentTime += Speed;
	if (CurrentTime >= (PreviousTime + 1.125f))
	{
		SpawnEnemy();
		PreviousTime = CurrentTime;
	}
	for (i = 0; i < EnemyCharacters.size(); i++)
	{
		EnemyCharacter *Enemies = EnemyCharacters[i];
		Enemies -> Update(Speed);
		if ((Enemies -> GetSprite().getPosition().x + Enemies -> GetSprite().getGlobalBounds().width) < 0)
		{
			EnemyCharacters.erase(EnemyCharacters.begin() + i);
			delete(Enemies);
		}
	}
	for (i = 0; i < EnemyBullets.size(); i++)
	{
		EnemyBullet* Bullets = EnemyBullets[i];
		Bullets -> Update(Speed);
		if ((Bullets -> GetSprite().getPosition().x) > TheGameWindow_CurrentDimensions.x)
		{
			EnemyBullets.erase(EnemyBullets.begin() + i);
			delete(Bullets);
		}
	}
	for (i = 0; i < EnemyCharacters.size(); i++)
	{
		EnemyCharacter *Enemies = EnemyCharacters[i];
		bool killed = false;
		for (j = 0; j < EnemyBullets.size(); j++)
		{
			EnemyBullet* Bullets = EnemyBullets[j];
			if(Enemies -> GetSprite().getGlobalBounds().intersects(Bullets -> GetSprite().getGlobalBounds()))
			{
				killed = true;
				if(Bullets->decreaseLife())
				{
					EnemyBullets.erase(EnemyBullets.begin() + j);
					delete(Bullets);
					break;
				}
			}
		}
		if(killed) {
			EnemyCharacters.erase(EnemyCharacters.begin() + i);
			delete(Enemies);
		}
	}
}

void SpawnEnemy()
{

	int RandomLocation = rand() % 3;
	sf::Vector2f EnemyCharacterPosition;
	float Speed;

	switch (RandomLocation)
	{
		case 0:
			EnemyCharacterPosition = sf::Vector2f(TheGameWindow_CurrentDimensions.x,TheGameWindow_CurrentDimensions.y * 0.75f);
			Speed = -400;
			break;
		case 1:
			EnemyCharacterPosition = sf::Vector2f(TheGameWindow_CurrentDimensions.x,TheGameWindow_CurrentDimensions.y * 0.60f);
			Speed = -550;
			break;
		case 2:
			EnemyCharacterPosition = sf::Vector2f(TheGameWindow_CurrentDimensions.x,TheGameWindow_CurrentDimensions.y * 0.40f);
			Speed = -650;
			break;
		default:
			return;
	}

	EnemyCharacter* Enemies = new EnemyCharacter();
	Enemies -> Init("Assets/EnemyCharacter.png", EnemyCharacterPosition,Speed);
	EnemyCharacters.push_back(Enemies);

}

void ShootBullets(int type)
{

	String bulletAssest;
	
	switch (type)
	{
		case 1:
			bulletAssest = "Assets/fireball_vector.png";
			break;
		case 2:
			bulletAssest = "Assets/iceball_vector.png";
			break;
		default:
			bulletAssest = "Assets/EnemyBullet.png";
			return;
	}

	EnemyBullet* Bullets = new EnemyBullet();
	Bullets -> Init(bulletAssest, GameCharacter.GetSprite().getPosition(), 400.0f, type);
	EnemyBullets.push_back(Bullets);

}