#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "../player/MainCharacterBullet.h"
#include <SFML/Graphics.hpp>
#include "../../../../library/src/header/MaterialButton.h"
#include "../App.h"
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

public:
    GameScreen()
    {

        gameMenuScreenBackground.setFillColor(Color(6, 117, 186));

    }

    ~GameScreen()
    {

    }

public:
    void draw(RenderWindow &window)
    {

        int i, j;

        gameMenuScreenBackground.setSize(Vector2f((float) window.getSize().x, (float) window.getSize().y));
        window.draw(gameMenuScreenBackground);

        vector<ItemModel *> mLvlItems = mGameMap->getItemsByLvl(mApp->getLvlSelected());
        for (ItemModel *mItem : mLvlItems)
        {
            RectangleShape item;
            item.setFillColor(Color(6, 209, 50));
            item.setPosition(Vector2f((float) mItem->getStartPos().x, (float) mItem->getStartPos().y));
            item.setSize(Vector2f((float) mItem->getSize().x, (float) mItem->getSize().y));
            window.draw(item);
        }

        window.draw(mMainCharacter->getSprite());

        for (MainCharacterBullet *mMainCharacterBullet : mMainCharacterBullets)
        {
            window.draw(mMainCharacterBullet->getSprite());
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

        MainCharacterBullet *mMainCharacterBullet = new MainCharacterBullet();
        mMainCharacterBullet->init(mMainCharacter->getCharacterPosition(), type, mMainCharacter->faceRight());
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
            shootBullets(3);
        }
    }

    void update(float speed)
    {

        int i, j;

        mMainCharacter->update(speed);

        for (i = 0; i < mMainCharacterBullets.size(); i++)
        {
            MainCharacterBullet *mMainCharacterBullet = mMainCharacterBullets[i];
            mMainCharacterBullet->update(speed);
            if ((mMainCharacterBullet->getSprite().getPosition().x) > WindowX)
            {
                mMainCharacterBullets.erase(mMainCharacterBullets.begin() + i);
                delete (mMainCharacterBullet);
            }
        }

    }

};
