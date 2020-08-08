//The Enemy Character Class Implementation...

//Header Files
#include <SFML/Graphics.hpp>

class EnemyCharacter
{
//...

//Main Class "EnemyCharacter()"
public:
	EnemyCharacter();
	~EnemyCharacter();
	void Init(std::string TextureName, sf::Vector2f Position, float MovingSpeed);
	void Update(float Speed);
	sf::Sprite GetSprite();

private:
	sf::Texture EnemyCharacterTexture;
	sf::Sprite EnemyCharacterSprite;
	sf::Vector2f EnemyCharacterPosition;
	float EnemyCharacterMovingSpeed;
};