//The Enemy Bullet Class Implementation...

//Header Files
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet()
{
//Local Variables

//Main "EnemyBullet()"

}

EnemyBullet::~EnemyBullet()
{
//Local Variables

//Main "~EnemyBullet()"

}

void EnemyBullet::Init(std::string TextureName, sf::Vector2f Position, float BulletSpeed)
{
//Local Variables

//Main "Init()"
	EnemyBulletSpeed = BulletSpeed;
	BulletPosition = Position;

	BulletTexture.loadFromFile(TextureName.c_str()); //We Load The Enemy Bullet Texture.

	BulletSprite.setTexture(BulletTexture); //We Create The Sprite For The Emeny Bullet & We Attach The Texture.
	BulletSprite.setPosition(BulletPosition);
	BulletSprite.setOrigin(BulletTexture.getSize().x / 2,BulletTexture.getSize().y / 2);
}

void EnemyBullet::Update(float Speed)
{
//Local Variables

//Main "Update()"
	BulletSprite.move(EnemyBulletSpeed * Speed,0);
}

sf::Sprite EnemyBullet::GetSprite()
{
//Local Variables

//Main "GetSprite()"

return BulletSprite;
}