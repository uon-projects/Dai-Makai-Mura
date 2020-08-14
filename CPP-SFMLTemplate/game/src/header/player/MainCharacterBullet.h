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
        mPosition.y -= 50;
        mInitialPosY = mPosition.y;
        mBulletPosition = mPosition;
        mClassType = mType;
        this->isRightFace = isRightFace;

        switch (mClassType)
        {
            case 1:
                mLifes = 1;
                mEnemyBulletSpeed *= 1.5;
                break;
            case 2:
                mLifes = 2;
                mEnemyBulletSpeed *= 0.8;
                break;
            default:
                return;
        }

        mBulletSprite = mApp->getFireSprite();
        mBulletSprite.setPosition(mBulletPosition);
        isRightFace ? (mBulletSprite.setScale(Vector2f(0.6, 0.6))) : (mBulletSprite.setScale(Vector2f(0.6, -0.6)));
        mBulletSprite.setRotation(-90);
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