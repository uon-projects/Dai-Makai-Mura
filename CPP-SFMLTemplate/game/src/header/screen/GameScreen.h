#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "../player/MainCharacterBullet.h"
#include <SFML/Graphics.hpp>
#include "../../../../library/src/header/MaterialButton.h"
#include "../App.h"
#include "../npc/NPCharacter.h"
#include "../player/MainCharacter.h"
#include "../game/GameMap.h"

using namespace std;
using namespace sf;

class GameScreen
{

private:
    RectangleShape gameMenuScreenBackground;
    App *mApp;
    MainCharacter *mMainCharacter;
    GameMap *mGameMap;
    vector<MainCharacterBullet *> mMainCharacterBullets;
    vector<NPCharacter *> mNPCharacters;
    int mColorEndPortal;
    bool mColorAscending;
    int mBgRI, mBgGI, mBgBI;
    int mBgRE, mBgGE, mBgBE;
    int mBackgroundR, mBackgroundG, mBackgroundB;

public:
    GameScreen()
    {

        mColorEndPortal = 77;
        mColorAscending = true;

        mBgRI = 32;
        mBgGI = 165;
        mBgBI = 227;

        mBgRE = 0;
        mBgGE = 0;
        mBgBE = 0;

    }

    ~GameScreen()
    {

    }

public:
    int getPercentColor(int mMaxHeight, int mColorMin, int mColorMax)
    {
        int mCharacterProgress = mMainCharacter->getGameHeight() * (-1);
        int mPercentProgress = (int) mCharacterProgress * 100 / mMaxHeight;
        int mColorArea = (abs)(mColorMin - mColorMax);
        if (mPercentProgress > 100)
        {
            mPercentProgress = 100;
        }
        int mColor = (100 - mPercentProgress) * mColorArea / 100;
        return mColor;
    }

    void draw(RenderWindow &window)
    {

        mBackgroundR = getPercentColor(1000, mBgRI, mBgRE);
        mBackgroundG = getPercentColor(1400, mBgGI, mBgGE);
        mBackgroundB = getPercentColor(2000, mBgBI, mBgBE);

        int i, j, mGameOffsetY;
        RectangleShape item;
        RectangleShape mEndPortal;

        mGameOffsetY = mApp->getGameOffsetY();

        gameMenuScreenBackground.setFillColor(Color(mBackgroundR, mBackgroundG, mBackgroundB));
        gameMenuScreenBackground.setSize(Vector2f((float) window.getSize().x, (float) window.getSize().y));
        window.draw(gameMenuScreenBackground);

        vector < ItemModel * > mLvlItems = mGameMap->getItemsByLvl(mApp->getLvlSelected());
        for (ItemModel *mItem : mLvlItems)
        {
            item.setFillColor(Color(168, 12, 147, 150));
            item.setPosition(Vector2f((float) mItem->getStartPos().x, (float) mItem->getStartPos().y + mGameOffsetY));
            item.setSize(Vector2f((float) mItem->getSize().x, (float) mItem->getSize().y));
            window.draw(item);
        }

        vector < ItemModel * > mEndPortals = mGameMap->getEndPortalByLvl(mApp->getLvlSelected());
        for (ItemModel *mEndPortalItem : mEndPortals)
        {
            mEndPortal.setFillColor(Color(232, 21, mColorEndPortal));
            if (mColorAscending)
            {
                mColorEndPortal++;
                if (mColorEndPortal == 155)
                {
                    mColorAscending = false;
                }
            } else
            {
                mColorEndPortal--;
                if (mColorEndPortal == 77)
                {
                    mColorAscending = true;
                }
            }
            mEndPortal.setPosition(Vector2f((float) mEndPortalItem->getStartPos().x,
                                            (float) mEndPortalItem->getStartPos().y + mGameOffsetY));
            mEndPortal.setSize(Vector2f((float) mEndPortalItem->getSize().x, (float) mEndPortalItem->getSize().y));
            window.draw(mEndPortal);
        }

        for (NPCharacter *mNPCharacter : mNPCharacters)
        {
            window.draw(mNPCharacter->getSprite());
        }

        window.draw(mMainCharacter->getSprite());

        for (MainCharacterBullet *mMainCharacterBullet : mMainCharacterBullets)
        {
            window.draw(mMainCharacterBullet->getSprite(mGameOffsetY));
        }

    }

    void initNPCs()
    {
        vector < ItemModel * > mNPCs = mGameMap->getNPCByLvl(mApp->getLvlSelected());
        NPCharacter *mNPCharacter;
        for (ItemModel *mNPC : mNPCs)
        {
            mNPCharacter = new NPCharacter(
                    mApp->getGameMap(),
                    mNPC->isFacingRight(),
                    mNPC->getStartPos().x,
                    mNPC->getStartPos().y,
                    mNPC->getArea()
            );
            mNPCharacters.push_back(mNPCharacter);
        }
    }

    void setApp(App *app)
    {
        this->mApp = app;
        mMainCharacter = mApp->getMainCharacter();
        mGameMap = mApp->getGameMap();
        mMainCharacter->setGameMap(mApp->getGameMap());
    }

    void shootBullets(int type)
    {

        MainCharacterBullet *mMainCharacterBullet = new MainCharacterBullet(mApp);
        Vector2f mPosition;
        mPosition.x = mMainCharacter->getCharacterPosition().x;
        mPosition.y = mMainCharacter->getGameHeight();
        mMainCharacterBullet->init(mPosition, type, mMainCharacter->faceRight());
        mMainCharacterBullets.push_back(mMainCharacterBullet);

    }

    void inputListener(Event event)
    {
        if (event.key.code == Keyboard::Space)
        {
            mMainCharacter->jump(650.0f);
        }
        if (event.key.code == Keyboard::X)
        {
            system("pause");
        }
        if (event.key.code == Keyboard::Left || event.key.code == Keyboard::A)
        {
            mMainCharacter->move(-20.0f);
        } else if (event.key.code == Keyboard::Right || event.key.code == Keyboard::D)
        {
            mMainCharacter->move(20.0f);
        } /*else if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)
        {
            cout << "up\n";
        } else if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)
        {
            cout << "down\n";
		} */
        if (event.key.code == Keyboard::Num1 || event.key.code == Keyboard::Numpad1)
        {
            shootBullets(1);
        } else if (event.key.code == Keyboard::Num2 || event.key.code == Keyboard::Numpad2)
        {
            shootBullets(2);
        } else if (event.key.code == Keyboard::Num3 || event.key.code == Keyboard::Numpad3)
        {
            shootBullets(1);
        }
    }

    void update(float speed)
    {

        int i, j, mGameOffsetY;
        RectangleShape mEndPortal;
        mGameOffsetY = mMainCharacter->getGameOffsetY();

        mMainCharacter->update(speed, mApp->getLvlSelected());

        for (i = 0; i < mMainCharacterBullets.size(); i++)
        {
            MainCharacterBullet *mMainCharacterBullet = mMainCharacterBullets[i];
            mMainCharacterBullet->update();
            if ((mMainCharacterBullet->getSprite(mGameOffsetY).getPosition().x) > WindowX)
            {
                mMainCharacterBullets.erase(mMainCharacterBullets.begin() + i);
                delete (mMainCharacterBullet);
            }
        }

        for (NPCharacter *mNPCharacter : mNPCharacters)
        {
            mNPCharacter->update(speed, mApp->getLvlSelected(), mMainCharacter->getGameOffsetY());
            if (mNPCharacter->getSprite().getGlobalBounds().intersects(mMainCharacter->getSprite().getGlobalBounds()))
            {
                mMainCharacter->jump(500.0f);
            }
        }

        for (i = 0; i < mNPCharacters.size(); i++)
        {
            NPCharacter *mNPCharacter = mNPCharacters[i];
            bool killed = false;
            for (j = 0; j < mMainCharacterBullets.size(); j++)
            {
                MainCharacterBullet *mMainCharacterBullet = mMainCharacterBullets[j];
                if (mNPCharacter->getSprite().getGlobalBounds().intersects(
                        mMainCharacterBullet->getSprite(mApp->getGameOffsetY()).getGlobalBounds()))
                {
                    killed = true;
                    if (mMainCharacterBullet->decreaseLife())
                    {
                        mMainCharacterBullets.erase(mMainCharacterBullets.begin() + j);
                        delete (mMainCharacterBullet);
                        break;
                    }
                }
            }
            if (killed)
            {
                mNPCharacters.erase(mNPCharacters.begin() + i);
                delete (mNPCharacter);
            }
        }

        vector < ItemModel * > mEndPortals = mGameMap->getEndPortalByLvl(mApp->getLvlSelected());
        for (ItemModel *mEndPortalItem : mEndPortals)
        {
            mEndPortal.setPosition(Vector2f((float) mEndPortalItem->getStartPos().x,
                                            (float) mEndPortalItem->getStartPos().y + mGameOffsetY));
            mEndPortal.setSize(Vector2f((float) mEndPortalItem->getSize().x, (float) mEndPortalItem->getSize().y));
            if (mEndPortal.getGlobalBounds().intersects(mMainCharacter->getSprite().getGlobalBounds()))
            {
                mApp->increaseLevelsUnlocked();
                mApp->setCurrentScreen(choose_lvl);
                mMainCharacter->jump(100.0f);
            }
        }

    }

    void initNewLvl()
    {
        mColorEndPortal = 77;
        mColorAscending = true;

        mBackgroundR = mBgRI;
        mBackgroundG = mBgGI;
        mBackgroundB = mBgBI;

        initNPCs();
    }

};
