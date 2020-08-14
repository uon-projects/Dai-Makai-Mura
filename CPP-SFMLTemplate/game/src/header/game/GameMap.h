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

    void addItem(int mLvl, int mStartPosX, int mStartPosY, int mSizeW, int mSizeH, int mType)
    {
        ItemModel *mItemModel;

        mItemModel = new ItemModel(
                mLvl,
                Vector2i(mStartPosX, mStartPosY),
                Vector2i(mSizeW, mSizeH),
                mType
        );
        mItems.push_back(mItemModel);
    }

    void initializeLvl1()
    {

        addItem(1, 0, 450, 800, 500, 0);
        addItem(1, 0, 300, 550, 20, 0);
        addItem(1, 565, 225, 70, 20, 0);
        addItem(1, 650, 150, 150, 20, 0);
        addItem(1, 790, 30, 10, 120, 1);

    }

    vector<ItemModel *> getItemsByLvl(int mLvl)
    {
        vector < ItemModel * > lvlItems;

        for (ItemModel *mItem : mItems)
        {
            if (mItem->getLvl() == mLvl && mItem->getType() == 0)
            {
                lvlItems.push_back(mItem);
            }
        }

        return lvlItems;
    }

    vector<ItemModel *> getEndPortalByLvl(int mLvl)
    {
        vector < ItemModel * > endPortals;

        for (ItemModel *mItem : mItems)
        {
            if (mItem->getLvl() == mLvl && mItem->getType() == 1)
            {
                endPortals.push_back(mItem);
            }
        }

        return endPortals;
    }

    int getNearestGroundLvl(int mLvl, Vector2f mSpriteLocStart, Vector2f mSpriteLocSize)
    {
        int mNearestGroundLvl = -1;
        int characterPosY = mSpriteLocStart.y + mSpriteLocSize.y;
        int characterPosSX = mSpriteLocStart.x + 70;
        int characterPosEX = mSpriteLocStart.x + mSpriteLocSize.x - 70;

        vector < ItemModel * > mLvlItems = getItemsByLvl(mLvl);

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
