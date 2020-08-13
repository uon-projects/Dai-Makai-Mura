#ifndef DAI_MAKAI_MURA_MAIN_CHARACTER_H
#define DAI_MAKAI_MURA_MAIN_CHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../game/GameMap.h"

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
    bool isRightFace;
    GameMap *mGameMap;

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
        mMainCharacterSprite.setOrigin(mTextureMainCharacterSize.x / 2, 0);
        isRightFace = true;

    }

    ~MainCharacter()
    {

    }

    void setGameMap(GameMap *mGameMap)
    {
        this->mGameMap = mGameMap;
    }

    void reset(int lvlSelected)
    {
        if (lvlSelected == 1)
        {
            mMainCharacterPosition = Vector2f(50.0f, 330.0f);
        } else
        {
            mMainCharacterPosition = Vector2f(100.0f, 100.0f);
        }
        mMainCharacterSprite.setPosition(mMainCharacterPosition);
    }

    RectangleShape getSprite()
    {
        mMainCharacterSprite.setPosition(mMainCharacterPosition);
        return mMainCharacterSprite;
    }

    Vector2f getCharacterPosition()
    {
        return mMainCharacterPosition;
    }

    void update(float mSpeed)
    {
        Vector2f mSpriteLocStart;
        mSpriteLocStart.x = mMainCharacterSprite.getGlobalBounds().left;
        mSpriteLocStart.y = mMainCharacterSprite.getGlobalBounds().top;
        Vector2f mSpriteLocSize;
        mSpriteLocSize.x = mMainCharacterSprite.getGlobalBounds().width;
        mSpriteLocSize.y = mMainCharacterSprite.getGlobalBounds().height;
        int mGroundLevel = mGameMap->getNearestGroundLvl(1, mSpriteLocStart, mSpriteLocSize) - mSpriteLocSize.y;

        mMainCharacterVelocity -= mMainCharacterMass * mMainCharacterGravity * mSpeed;
        mMainCharacterPosition.y -= mMainCharacterVelocity * mSpeed / 1.2;

        if (mMainCharacterJump && mMainCharacterOnMove)
        {
            if (mMainCharacterPosition.x + mMainCharacterVelocityMove * mSpeed * 8 < mTextureMainCharacterSize.x / 2)
            {
                mMainCharacterPosition.x = mTextureMainCharacterSize.x / 2;
            } else if (mMainCharacterPosition.x + mMainCharacterVelocityMove * mSpeed * 8 >
                       800 - mTextureMainCharacterSize.x / 2)
            {
                mMainCharacterPosition.x = 800 - mTextureMainCharacterSize.x / 2;
            } else
            {
                mMainCharacterPosition.x += mMainCharacterVelocityMove * mSpeed * 8;
            }
        } else if (mMainCharacterOnMove)
        {
            if (mMovesCount < 20)
            {
                mMainCharacterVelocityMove /= 1.1;
                if (mMainCharacterPosition.x + mMainCharacterVelocityMove * mSpeed * 24 <
                    mTextureMainCharacterSize.x / 2)
                {
                    mMainCharacterPosition.x = mTextureMainCharacterSize.x / 2;
                } else if (mMainCharacterPosition.x + mMainCharacterVelocityMove * mSpeed * 24 >
                           800 - mTextureMainCharacterSize.x / 2)
                {
                    mMainCharacterPosition.x = 800 - mTextureMainCharacterSize.x / 2;
                } else
                {
                    mMainCharacterPosition.x += mMainCharacterVelocityMove * mSpeed * 24;
                }
                mMovesCount++;
            } else
            {
                mMainCharacterOnMove = false;
            }
        }

        if (mMainCharacterPosition.y >= mGroundLevel)
        {
            mMainCharacterPosition.y = mGroundLevel;
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
            isRightFace = false;
        } else
        {
            mMainCharacterSprite.setScale(Vector2f(2.0f, 2.0f));
            isRightFace = true;
        }
        mMainCharacterVelocityMove = mVelocity;
        mMainCharacterOnMove = true;
        mMovesCount = 0;
    }

    bool faceRight()
    {
        return isRightFace;
    }

};

#endif //DAI_MAKAI_MURA_MAIN_CHARACTER_H
