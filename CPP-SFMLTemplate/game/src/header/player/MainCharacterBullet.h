#ifndef DAI_MAKAI_MURA_MAIN_CHARACTER_BULLET_H
#define DAI_MAKAI_MURA_MAIN_CHARACTER_BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../App.h"

using namespace std;
using namespace sf;

class MainCharacterBullet
{

private:
    Sprite mBulletSprite;
    Vector2f mBulletPosition;
    float mEnemyBulletSpeed;
    int mClassType;
    int mLifes;
    int mInitialPosY;
    bool isRightFace;
    App *mApp;
    float mScaleSprite;

public:
    MainCharacterBullet(App *app)
    {
        this->mApp = app;
    }

    ~MainCharacterBullet()
    {

    }

    void init(Vector2f mPosition, int mType, bool isRightFace)
    {
        mEnemyBulletSpeed = 4.0f;
        mClassType = mType;
        this->isRightFace = isRightFace;
        mScaleSprite = 0.3f;

        switch (mClassType)
        {
            case 1:
                mLifes = 1;
                mEnemyBulletSpeed *= 1.5;
                mPosition.y -= 53;
                mPosition.x = isRightFace ? (mPosition.x + 15) : (mPosition.x - 15);
                mScaleSprite = 0.3f;
                mBulletSprite = mApp->getBullet1Sprite();
                break;
            case 2:
                mLifes = 2;
                mEnemyBulletSpeed *= 0.8;
                mPosition.y -= 55;
                mPosition.x = isRightFace ? (mPosition.x + 15) : (mPosition.x - 15);
                mScaleSprite = 0.4f;
                mBulletSprite = mApp->getBullet2Sprite();
                break;
            default:
                return;
        }

        mInitialPosY = mPosition.y;
        mBulletPosition = mPosition;
        mBulletSprite.setPosition(mBulletPosition);
        isRightFace ? (mBulletSprite.setScale(Vector2f(mScaleSprite, mScaleSprite))) : (mBulletSprite.setScale(Vector2f(-mScaleSprite, mScaleSprite)));
        mBulletSprite.setRotation(0);
    }

    void update()
    {
        mBulletPosition.x = mBulletPosition.x + (mEnemyBulletSpeed * (isRightFace ? 1 : -1));
        mBulletSprite.setPosition(mBulletPosition);
    }

    Sprite getSprite(int mGameOffsetY)
    {
        mBulletPosition.y = mGameOffsetY + mInitialPosY;
        mBulletSprite.setPosition(mBulletPosition);
        return mBulletSprite;
    }

    bool decreaseLife()
    {
        mLifes--;
        return mLifes == 0;
    }

};

#endif //DAI_MAKAI_MURA_MAIN_CHARACTER_BULLET_H