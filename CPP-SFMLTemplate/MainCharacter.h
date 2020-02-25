//The Main Character Class Declaration...

//Header Files
#include <SFML/Graphics.hpp>

class MainCharacter
{
//...

//Main Class "MainCharacter()"
public:
	MainCharacter();
	~MainCharacter();
	void Init(std::string TextureName,sf::Vector2f Position,float Mass);
	void Update(float Speed);
	void Move(float Velocity);
	void Jump(float Velocity);
	sf::RectangleShape GetSprite();

private:
	sf::Texture MainCharacterTexture;
	sf::RectangleShape MainCharacterSprite;
	sf::Vector2f MainCharacterPosition;
	int JumpCount;
	int MovesCount;
	sf::Vector2u textureMainCharacterSize;
	float MainCharacterMass;
	float MainCharacterVelocity;
	float MainCharacterVelocityMove;
	float MainCharacterGravity; //The Average Value At Earth's Surface (Standard Gravity) is, by definition, 9.80665 m/s^2 (9.80f).
	bool MainCharacterOnGround;
	bool MainCharacterOnMove;
};