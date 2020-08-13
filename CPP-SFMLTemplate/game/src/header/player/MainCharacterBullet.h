#ifndef DAI_MAKAI_MURA_MAIN_CHARACTER_BULLET_H
#define DAI_MAKAI_MURA_MAIN_CHARACTER_BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class MainCharacterBullet
{

private:
    Texture mBulletTexture;
    RectangleShape mBulletSprite;
    Vector2u mBulletSize;
    Vector2f mBulletPosition;
    float mEnemyBulletSpeed;
    int mClassType;
    int mLifes;
    bool isRightFace;

public:
    MainCharacterBullet()
    {

    }

    ~MainCharacterBullet()
    {

    }

    void init(Vector2f mPosition, int mType, bool isRightFace)
    {
        mEnemyBulletSpeed = 400.0f;
        mPosition.y += 55;
        mBulletPosition = mPosition;
        mClassType = mType;
        this->isRightFace = isRightFace;

        switch (mClassType)
        {
            case 1:
                mEnemyBulletSpeed *= 0.8;
                mBulletTexture.loadFromFile("game/src/res/vector/fireball_character.png");
                mBulletSize = mBulletTexture.getSize();
                mBulletSize.x /= 10;
                mBulletSize.y /= 5;
                mLifes = 1;
                break;
            case 2:
                mEnemyBulletSpeed *= 2;
                mBulletTexture.loadFromFile("game/src/res/vector/iceball_character.png");
                mBulletSize = mBulletTexture.getSize();
                mBulletSize.x /= 11;
                mBulletSize.y /= 6;
                mLifes = 2;
                break;
            default:
                return;
        }

        mBulletPosition.y += 30;

        mBulletSprite.setSize(Vector2f(60, 110));
        mBulletSprite.setTexture(&mBulletTexture);
        mBulletSprite.setTextureRect(IntRect(mBulletSize.x * 0, mBulletSize.y * 0, mBulletSize.x, mBulletSize.y));
        mBulletSprite.setPosition(mBulletPosition);
        isRightFace ? (mBulletSprite.setScale(Vector2f(0.6, 0.6))) : (mBulletSprite.setScale(Vector2f(0.6, -0.6)));
        mBulletSprite.setRotation(-90);
        mBulletSprite.setOrigin(mBulletSize.x / 2, mBulletSize.y / 2);
    }

    void update(float speed)
    {
        mBulletSprite.move(mEnemyBulletSpeed * (isRightFace ? speed : speed * (-1)), 0);
    }

    RectangleShape getSprite()
    {
        return mBulletSprite;
    }

    bool decreaseLife()
    {
        mLifes--;
        return mLifes == 0;
    }

};

#endif //DAI_MAKAI_MURA_MAIN_CHARACTER_BULLET_H