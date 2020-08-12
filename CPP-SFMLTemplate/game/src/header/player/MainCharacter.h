#ifndef DAI_MAKAI_MURA_MAIN_CHARACTER_H
#define DAI_MAKAI_MURA_MAIN_CHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

using namespace sf;

class MainCharacter
{

private:
    Texture mMainCharacterTexture;
    RectangleShape mMainCharacterSprite;
    Vector2f mMainCharacterPosition;
    int mJumpCount;
    int mMovesCount;
    Vector2u mTextureMainCharacterSize;
    float mMainCharacterMass;
    float mMainCharacterVelocity;
    float mMainCharacterVelocityMove;
    float mMainCharacterGravity; //The Average Value At Earth's Surface (Standard Gravity) is, by definition, 9.80665 m/s^2 (9.80f).
    bool mMainCharacterOnGround;
    bool mMainCharacterOnMove;

public:
    MainCharacter()
    {

        mMainCharacterMass = 200.0f;
        mMainCharacterOnGround = false;
        mMainCharacterOnMove = false;

        mMainCharacterTexture.loadFromFile("game/src/res/vector/main_character.png");
        mTextureMainCharacterSize = mMainCharacterTexture.getSize();
        mTextureMainCharacterSize.x /= 18;
        mTextureMainCharacterSize.y /= 19;

        mMainCharacterSprite.setSize(Vector2f(60, 60));
        mMainCharacterSprite.setTexture(&mMainCharacterTexture);
        mMainCharacterSprite.setTextureRect(
                IntRect(mTextureMainCharacterSize.x * 7, mTextureMainCharacterSize.y * 0, mTextureMainCharacterSize.x,
                        mTextureMainCharacterSize.y));
        mMainCharacterSprite.setScale(Vector2f(2.0f, 2.0f));
        mMainCharacterSprite.setOrigin(mTextureMainCharacterSize.x / 2, mTextureMainCharacterSize.y / 2);

    }

    ~MainCharacter()
    {

    }

    void reset()
    {
        cout<<"Reset!";
        mMainCharacterPosition = Vector2f(400.0f, 300.0f);
        mMainCharacterSprite.setPosition(mMainCharacterPosition);
        mMainCharacterSprite.setPosition(Vector2f(300.0f, 200.0f));
    }

    RectangleShape getSprite()
    {
        return mMainCharacterSprite;
    }

};

#endif //DAI_MAKAI_MURA_MAIN_CHARACTER_H
