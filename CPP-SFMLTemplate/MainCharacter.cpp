//The Main Character Class Implementation...

//Header Files
#include "MainCharacter.h"

MainCharacter::MainCharacter()
{
//Local Variables

//Main "MainCharacter()"
	JumpCount = 0;
	MainCharacterGravity = 8.0f;

}

MainCharacter::~MainCharacter()
{
//Local Variables

//Main "~MainCharacter()"

}

void MainCharacter::Init(std::string TextureName, sf::Vector2f Position,float Mass)
{
//Local Variables

//Main "Init()"
	MainCharacterPosition = Position;
	MainCharacterMass = Mass;
	MainCharacterOnGround = false;

	MainCharacterTexture.loadFromFile(TextureName.c_str()); //We Create The Texture For The Main character.
	MainCharacterSprite.setTexture(MainCharacterTexture); //We Create The Main Character Sprite & We Attach To It The Texture.
	MainCharacterSprite.setPosition(MainCharacterPosition);
	MainCharacterSprite.setOrigin(MainCharacterTexture.getSize().x / 2,MainCharacterTexture.getSize().y / 2);
}

void MainCharacter::Update(float Speed)
{
//Local Variables
	int GroundLevel = 518;

//Main "Update()"
	MainCharacterVelocity -= MainCharacterMass * MainCharacterGravity * Speed;
	MainCharacterPosition.y -= MainCharacterVelocity * Speed;
	MainCharacterSprite.setPosition(MainCharacterPosition);
	if (MainCharacterPosition.y >= (GroundLevel * 0.75f))
		{
		MainCharacterPosition.y = GroundLevel * 0.75f;
		MainCharacterVelocity = 0;
		MainCharacterOnGround = true;
		JumpCount = 0;
		}
}

void MainCharacter::Jump(float Velocity)
{
//Local Variables

//Main "Jump()"
	if (JumpCount < 2)
		{
		JumpCount++;
		MainCharacterVelocity = Velocity;
		MainCharacterOnGround = false;
		}
}

sf::Sprite MainCharacter::GetSprite()
{
//Local Variables

//Main "GetSprite()"

return MainCharacterSprite;
}