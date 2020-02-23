//The Enemy Bullet Class Declaration...

//Header Files
#include <SFML/Graphics.hpp>

class EnemyBullet
{
//...

//Main Class "Bullet()"
public:
	EnemyBullet();
	~EnemyBullet();
	void Init(std::string TextureName, sf::Vector2f Position, float BulletSpeed, int type);
	void Update(float Speed);
	sf::Sprite GetSprite();

private:
	sf::Texture BulletTexture;
	sf::Sprite BulletSprite;
	sf::Vector2f BulletPosition;
	float EnemyBulletSpeed;
	int classType;
};