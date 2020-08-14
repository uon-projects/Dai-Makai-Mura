#ifndef DAI_MAKAI_MURA_NPCHARACTER_H
#define DAI_MAKAI_MURA_NPCHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../game/GameMap.h"

using namespace std;
using namespace sf;

class NPCharacter
{

private:
    GameMap *mGameMap;
    Texture mMainCharacterTexture;
    RectangleShape mMainCharacterSprite;
    Vector2u mTextureMainCharacterSize;
    bool isRightFace;
    float mMainCharacterGravity; //The Average Value At Earth's Surface (Standard Gravity) is, by definition, 9.80665 m/s^2 (9.80f).
    float mMainCharacterMass;
    float mMainCharacterVelocity;
    Vector2f mMainCharacterPosition;
    int mMovingRange;
    int mCurrentMoved;
    float mMainCharacterVelocityMove;

public:
    NPCharacter(GameMap *mGameMap, bool isRightFace, float startX, float startY, int range)
    {
        this->mGameMap = mGameMap;
        this->isRightFace = isRightFace;
        this->mMovingRange = range;
        this->mMainCharacterPosition.x = startX;
        this->mMainCharacterPosition.y = startY;

        mMainCharacterMass = 200.0f;
        mMainCharacterVelocity = 650.0f;
        mMainCharacterGravity = 8.0f;

        mCurrentMoved = 0;

        mMainCharacterTexture.loadFromFile("game/src/res/vector/main_character.png");
        mTextureMainCharacterSize = mMainCharacterTexture.getSize();
        mTextureMainCharacterSize.x /= 18;
        mTextureMainCharacterSize.y /= 19;
        mMainCharacterVelocity = 20.0f;

        mMainCharacterSprite.setSize(Vector2f(60, 60));
        mMainCharacterSprite.setTexture(&mMainCharacterTexture);
        mMainCharacterSprite.setTextureRect(
                IntRect(mTextureMainCharacterSize.x * 0, mTextureMainCharacterSize.y * 0, mTextureMainCharacterSize.x,
                        mTextureMainCharacterSize.y));
        mMainCharacterSprite.setScale(Vector2f(2.0f, 2.0f));
        mMainCharacterSprite.setOrigin(mTextureMainCharacterSize.x / 2, 0);
    }

    ~NPCharacter()
    {

    }

    void update(float mSpeed)
    {
        Vector2f mSpriteLocStart;
        mSpriteLocStart.x = mMainCharacterSprite.getGlobalBounds().left;
        mSpriteLocStart.y = mMainCharacterSprite.getGlobalBounds().top;
        Vector2f mSpriteLocSize;
        mSpriteLocSize.x = mMainCharacterSprite.getGlobalBounds().width;
        mSpriteLocSize.y = mMainCharacterSprite.getGlobalBounds().height;
        int mGroundLevel = mGameMap->getNearestGroundLvl(1, mSpriteLocStart, mSpriteLocSize, 0) - mSpriteLocSize.y;

        mMainCharacterVelocity -= mMainCharacterMass * mMainCharacterGravity * mSpeed;
        mMainCharacterPosition.y -= mMainCharacterVelocity * mSpeed / 1.2;

        isRightFace ? (mMainCharacterSprite.setScale(Vector2f(2.0f, 2.0f))) : (mMainCharacterSprite.setScale(
                Vector2f(-2.0f, 2.0f)));
        isRightFace ? (mMainCharacterPosition.x += 1) : (mMainCharacterPosition.x -= 1);

        mCurrentMoved += 1;
        if (mCurrentMoved >= mMovingRange)
        {
            mCurrentMoved = 0;
            isRightFace = !isRightFace;
        }
        if (mMainCharacterPosition.y >= mGroundLevel)
        {
            mMainCharacterPosition.y = (float) mGroundLevel;
        }

        mMainCharacterSprite.setPosition(mMainCharacterPosition);
    }

    RectangleShape getSprite()
    {
        mMainCharacterSprite.setPosition(mMainCharacterPosition);
        return mMainCharacterSprite;
    }

};

#endif //DAI_MAKAI_MURA_NPCHARACTER_H
