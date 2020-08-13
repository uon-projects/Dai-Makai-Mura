#ifndef DAI_MAKAI_MURA_GAMEMAP_H
#define DAI_MAKAI_MURA_GAMEMAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "./ItemModel.h"

using namespace std;
using namespace sf;

class GameMap
{

private:
    vector<ItemModel *> mItems;

public:
    GameMap()
    {
        initialize();
    }

    ~GameMap()
    {

    }

    void initialize()
    {
        initializeLvl1();
    }

    void initializeLvl1()
    {
        ItemModel *mItemModel;

        mItemModel = new ItemModel(
                1,
                Vector2i(0, 450),
                Vector2i(800, 50)
        );
        mItems.push_back(mItemModel);

        mItemModel = new ItemModel(
                1,
                Vector2i(100, 300),
                Vector2i(700, 20)
        );
        mItems.push_back(mItemModel);
    }

    vector<ItemModel *> getItemsByLvl(int mLvl)
    {
        vector < ItemModel * > lvlItems;

        for (ItemModel *mItem : mItems)
        {
            if (mItem->getLvl() == mLvl)
            {
                lvlItems.push_back(mItem);
            }
        }

        return lvlItems;
    }

    int getNearestGroundLvl(int mLvl, Vector2f mSpriteLocStart, Vector2f mSpriteLocSize)
    {
        int mNearestGroundLvl = -1;
        int characterPosY = mSpriteLocStart.y + mSpriteLocSize.y;
        int characterPosSX = mSpriteLocStart.x + 50;
        int characterPosEX = mSpriteLocStart.x + mSpriteLocSize.x - 50;

        vector < ItemModel * > mLvlItems = this->getItemsByLvl(mLvl);

        for (ItemModel *mItem : mLvlItems)
        {
            int itemPosSX = mItem->getStartPos().x;
            int itemPosEX = mItem->getSize().x + mItem->getStartPos().x;
            if (mItem->getStartPos().y >= characterPosY && mNearestGroundLvl == -1)
            {
                if (itemPosSX <= characterPosSX && itemPosEX >= characterPosEX)
                {
                    mNearestGroundLvl = mItem->getStartPos().y;
                }
            } else if (mNearestGroundLvl != -1 && mItem->getStartPos().y >= characterPosY &&
                       mNearestGroundLvl > mItem->getStartPos().y)
            {
                if (itemPosSX <= characterPosSX && itemPosEX >= characterPosEX)
                {
                    mNearestGroundLvl = mItem->getStartPos().y;
                }
            }
        }
        return mNearestGroundLvl;
    }

};

#endif //DAI_MAKAI_MURA_GAMEMAP_H
