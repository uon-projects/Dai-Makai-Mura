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
    bool mMainCharacterJump;
    bool mMainCharacterOnMove;

public:
    MainCharacter()
    {

        mJumpCount = 0;
        mMovesCount = 0;
        mMainCharacterGravity = 8.0f;

        mMainCharacterMass = 200.0f;
        mMainCharacterJump = false;
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
        mMainCharacterPosition = Vector2f(300.0f, 200.0f);
        mMainCharacterSprite.setPosition(mMainCharacterPosition);
    }

    RectangleShape getSprite()
    {
        mMainCharacterSprite.setPosition(mMainCharacterPosition);
        return mMainCharacterSprite;
    }

    void update(float mSpeed)
    {
        int mGroundLevel = 460;

        mMainCharacterVelocity -= mMainCharacterMass * mMainCharacterGravity * mSpeed;
        mMainCharacterPosition.y -= mMainCharacterVelocity * mSpeed / 1.2;

        if (mMainCharacterJump && mMainCharacterOnMove)
        {
            mMainCharacterPosition.x += mMainCharacterVelocityMove * mSpeed * 8;
        } else if (mMainCharacterOnMove)
        {
            if (mMovesCount < 20)
            {
                mMainCharacterVelocityMove /= 1.1;
                mMainCharacterPosition.x += mMainCharacterVelocityMove * mSpeed * 24;
                mMovesCount++;
            } else
            {
                mMainCharacterOnMove = false;
            }
        }

        if (mMainCharacterPosition.y >= (mGroundLevel * 0.75f))
        {
            mMainCharacterPosition.y = mGroundLevel * 0.75f;
            mMainCharacterVelocity = 0;
            if (mMainCharacterJump)
            {
                mMovesCount = 12;
                mMainCharacterVelocityMove /= 1.6;
            } else
            {

            }
            mMainCharacterJump = false;
            mJumpCount = 0;
        }

        mMainCharacterSprite.setPosition(mMainCharacterPosition);
    }

    void jump(float mVelocity)
    {
        if (mJumpCount < 2)
        {
            mJumpCount++;
            mMainCharacterVelocity = mVelocity;
            mMainCharacterJump = true;
        }
    }

    void move(float mVelocity)
    {
        if (mVelocity < 0)
        {
            mMainCharacterSprite.setScale(Vector2f(-2.0f, 2.0f));
        } else
        {
            mMainCharacterSprite.setScale(Vector2f(2.0f, 2.0f));
        }
        mMainCharacterVelocityMove = mVelocity;
        mMainCharacterOnMove = true;
        mMovesCount = 0;
    }

};

#endif //DAI_MAKAI_MURA_MAIN_CHARACTER_H
