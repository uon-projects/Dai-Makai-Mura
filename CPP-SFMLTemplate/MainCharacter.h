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
	void Jump(float Velocity);
	sf::Sprite GetSprite();

private:
	sf::Texture MainCharacterTexture;
	sf::Sprite MainCharacterSprite;
	sf::Vector2f MainCharacterPosition;
	int JumpCount;
	float MainCharacterMass;
	float MainCharacterVelocity;
	float MainCharacterGravity; //The Average Value At Earth's Surface (Standard Gravity) is, by definition, 9.80665 m/s^2 (9.80f).
	bool MainCharacterOnGround;
};