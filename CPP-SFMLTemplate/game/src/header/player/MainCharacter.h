#ifndef DAI_MAKAI_MURA_MAIN_CHARACTER_H
#define DAI_MAKAI_MURA_MAIN_CHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../game/GameMap.h"
#include "../../../../library/src/header/LoadImage.h"

using namespace std;
using namespace sf;

class MainCharacter
{

private:
    Sprite mMainCharacterSprite;
    float mCharacterScale;
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
    int mGameOffsetY;
    LoadImage *mLoadImage;

public:
    MainCharacter()
    {
        mLoadImage = new LoadImage();

        mJumpCount = 0;
        mMovesCount = 0;
        mMainCharacterGravity = 8.0f;
        mMainCharacterVelocity = 20.0f;

        mMainCharacterMass = 200.0f;
        mMainCharacterJump = false;
        mMainCharacterOnMove = false;

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
        mMainCharacterPosition = mGameMap->getCharacterStartPos(lvlSelected);
        mGameOffsetY = getGameOffsetY();

        mJumpCount = 0;
        mMovesCount = 0;
        mMainCharacterGravity = 8.0f;

        mMainCharacterMass = 200.0f;
        mMainCharacterJump = false;
        mMainCharacterOnMove = false;

        mMainCharacterSprite = mLoadImage->loadSpriteFromTexture("Idle__000", png);
        mCharacterScale = 0.2f;
        mMainCharacterSprite.setScale(Vector2f(mCharacterScale, mCharacterScale));
        mTextureMainCharacterSize.x = mMainCharacterSprite.getGlobalBounds().width;
        mTextureMainCharacterSize.y = mMainCharacterSprite.getGlobalBounds().height;
        mMainCharacterSprite.setOrigin(Vector2f(mTextureMainCharacterSize.x / 2, 0));
    }

    int getGameOffsetY()
    {
        if (mMainCharacterPosition.y > -170)
        {
            mGameOffsetY = 500;
        } else
        {
            mGameOffsetY = 500 - mMainCharacterPosition.y - 170;
        }
        return mGameOffsetY;
    }

    Sprite getSprite()
    {
        mMainCharacterPosition.y += mGameOffsetY;
        mMainCharacterPosition.y -= mMainCharacterSprite.getGlobalBounds().height;
        mMainCharacterSprite.setPosition(mMainCharacterPosition);
        mMainCharacterPosition.y -= mGameOffsetY;
        mMainCharacterPosition.y += mMainCharacterSprite.getGlobalBounds().height;
        return mMainCharacterSprite;
    }

    Vector2f getCharacterPosition()
    {
        Vector2f mPos;
        mPos.y += mGameOffsetY;
        mPos.y -= mMainCharacterSprite.getGlobalBounds().height;
        mPos.x = mMainCharacterPosition.x;
        return mPos;
    }

    int getGameHeight()
    {
        int gameHeight = 0;
        if (mMainCharacterPosition.y > -170)
        {
            mGameOffsetY = 500;
        } else
        {
            mGameOffsetY = 500 - mMainCharacterPosition.y - 170;
        }
        return mMainCharacterPosition.y;
    }

    void update(float mSpeed, int mLvlSelected)
    {
        mMainCharacterSprite = getSprite();
        Vector2f mSpriteLocStart;
        mSpriteLocStart.x = mMainCharacterSprite.getGlobalBounds().left;
        mSpriteLocStart.y = mMainCharacterPosition.y;
        Vector2f mSpriteLocSize;
        mSpriteLocSize.x = mMainCharacterSprite.getGlobalBounds().width;
        mSpriteLocSize.y = mMainCharacterSprite.getGlobalBounds().height;
        int mGroundLevel = mGameMap->getNearestGroundLvl(mLvlSelected, mSpriteLocStart, mSpriteLocSize, mGameOffsetY);
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
                    mTextureMainCharacterSize.x)
                {
                    mMainCharacterPosition.x = mTextureMainCharacterSize.x;
                } else if (mMainCharacterPosition.x + mMainCharacterVelocityMove * mSpeed * 24 >
                           800 - mTextureMainCharacterSize.x)
                {
                    mMainCharacterPosition.x = 800 - mTextureMainCharacterSize.x;
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
            mMainCharacterPosition.y = (float) mGroundLevel;
            mMainCharacterVelocity = 0;
            if (mMainCharacterJump)
            {
                mMovesCount = 12;
                mMainCharacterVelocityMove /= 1.6f;
            } else
            {

            }
            mMainCharacterJump = false;
            mJumpCount = 0;
        }
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
            mMainCharacterSprite.setScale(Vector2f(-mCharacterScale, mCharacterScale));
            isRightFace = false;
        } else
        {
            mMainCharacterSprite.setScale(Vector2f(mCharacterScale, mCharacterScale));
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
