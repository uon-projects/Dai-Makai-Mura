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
    vector<ItemModel *> mCharacterStartPos;
    vector<ItemModel *> mNPCStartPos;

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
        initializeStartPos();
        initializeNPCs();
        initializeLvl1();
        initializeLvl2();
        initializeLvl3();
        initializeLvl4();
    }

    void addStartPos(int mLvl, int mStartPosX, int mStartPosY)
    {
        ItemModel *mItemModel;

        mStartPosY *= -1;
        mItemModel = new ItemModel(
                mLvl,
                Vector2i(mStartPosX, mStartPosY)
        );
        mCharacterStartPos.push_back(mItemModel);
    }

    void addNPCStartPos(int mLvl, int mStartPosX, int mStartPosY, int mArea, bool mFaceRight)
    {
        ItemModel *mItemModel;

        mStartPosY *= -1;
        mItemModel = new ItemModel(
                mLvl,
                Vector2i(mStartPosX, mStartPosY),
                mArea,
                mFaceRight
        );
        mNPCStartPos.push_back(mItemModel);
    }

    vector<ItemModel *> getNPCByLvl(int mLvl)
    {
        vector < ItemModel * > npcList;
        for (ItemModel *mNPC : mNPCStartPos)
        {
            if (mNPC->getLvl() == mLvl)
            {
                npcList.push_back(mNPC);
            }
        }

        return npcList;
    }

    Vector2f getCharacterStartPos(int mLvl)
    {
        Vector2f mStartPosOfLvl = Vector2f(0.0f, 0.0f);
        for (ItemModel *mStartPos : mCharacterStartPos)
        {
            if (mStartPos->getLvl() == mLvl)
            {
                mStartPosOfLvl.x = mStartPos->getStartPos().x;
                mStartPosOfLvl.y = mStartPos->getStartPos().y;
            }
        }

        return mStartPosOfLvl;
    }

    void addItem(int mLvl, int mStartPosX, int mStartPosY, int mSizeW, int mSizeH, int mType)
    {
        ItemModel *mItemModel;

        mStartPosY *= -1;
        mItemModel = new ItemModel(
                mLvl,
                Vector2i(mStartPosX, mStartPosY - mSizeH),
                Vector2i(mSizeW, mSizeH),
                mType
        );
        mItems.push_back(mItemModel);
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

    int getNearestGroundLvl(int mLvl, Vector2f mSpriteLocStart, Vector2f mSpriteLocSize, int mGameOffsetY = 0)
    {
        int mNearestGroundLvl = 0;

        int characterPosY = mSpriteLocStart.y;
        int characterPosSX = mSpriteLocStart.x + 50;
        int characterPosEX = mSpriteLocStart.x + mSpriteLocSize.x - 50;

        vector < ItemModel * > mLvlItems = getItemsByLvl(mLvl);
        for (ItemModel *mItem : mLvlItems)
        {
            int itemPosSX = mItem->getStartPos().x - 30;
            int itemPosEX = mItem->getSize().x + mItem->getStartPos().x + 30;
            int itemPosY = mItem->getStartPos().y;
            if (itemPosY >= characterPosY)
            {
                if (characterPosSX >= itemPosSX && characterPosEX <= itemPosEX)
                {
                    if (mNearestGroundLvl == 0)
                    {
                        mNearestGroundLvl = itemPosY;
                    } else if (mNearestGroundLvl >= characterPosY)
                    {
                        mNearestGroundLvl = itemPosY;
                    }
                }
            }
        }
        return mNearestGroundLvl;
    }

    void initializeStartPos()
    {
        addStartPos(1, 100, 50);
        addStartPos(2, 600, 50);
        addStartPos(3, 225, 80);
    }

    void initializeNPCs()
    {
        //lvl 1
        addNPCStartPos(1, 400, 50, 200, true);
        addNPCStartPos(1, 620, 500, 240, false);
        addNPCStartPos(1, 430, 500, 140, false);

        //lvl 2
        addNPCStartPos(2, 70, 50, 300, true);
        addNPCStartPos(2, 675, 320, 100, false);

        //lvl 3
        addNPCStartPos(3, 600, 190, 100, true);
        addNPCStartPos(3, 300, 360, 120, false);
        addNPCStartPos(3, 70, 480, 120, true);
        addNPCStartPos(3, 70, 640, 300, true);
        addNPCStartPos(3, 370, 640, 300, false);
        addNPCStartPos(3, 240, 800, 60, false);
        addNPCStartPos(3, 260, 800, 60, true);
    }

    void initializeLvl1()
    {

        //blocks
        addItem(1, 0, 0, 800, 50, 0);
        addItem(1, 250, 150, 100, 20, 0);
        addItem(1, 375, 250, 100, 20, 0);
        addItem(1, 250, 350, 100, 20, 0);
        addItem(1, 375, 450, 425, 20, 0);

        //portals
        addItem(1, 790, 470, 10, 120, 1);

    }

    void initializeLvl2()
    {

        //blocks
        addItem(2, 0, 0, 800, 50, 0);
        addItem(2, 250, 150, 100, 20, 0);
        addItem(2, 375, 300, 425, 20, 0);
        addItem(2, 375, 450, 75, 20, 0);
        addItem(2, 525, 450, 275, 20, 0);
        addItem(2, 100, 550, 250, 20, 0);
        addItem(2, 300, 700, 400, 20, 0);
        addItem(2, 450, 800, 100, 20, 0);

        //portals
        addItem(2, 475, 1050, 50, 20, 1);

    }

    void initializeLvl3()
    {

        //blocks
        addItem(3, 50, 60, 500, 20, 0);
        addItem(3, 600, 170, 100, 20, 0);
        addItem(3, 450, 280, 100, 20, 0);
        addItem(3, 600, 390, 100, 20, 0);
        addItem(3, 450, 500, 100, 20, 0);
        addItem(3, 600, 610, 100, 20, 0);
        addItem(3, 450, 720, 100, 20, 0);
        addItem(3, 150, 340, 200, 20, 0);
        addItem(3, 50, 460, 175, 20, 0);
        addItem(3, 0, 620, 400, 20, 0);
        addItem(3, 200, 780, 125, 20, 0);
        addItem(3, 400, 900, 80, 20, 0);
        addItem(3, 300, 1020, 120, 20, 0);
        addItem(3, 50, 1100, 150, 20, 0);

        //portals
        addItem(3, 50, 1120, 20, 100, 1);

    }

    void initializeLvl4()
    {

        //blocks
        addItem(2, 0, 0, 800, 50, 0);
        addItem(2, 250, 150, 100, 20, 0);
        addItem(2, 375, 300, 425, 20, 0);
        addItem(2, 375, 450, 75, 20, 0);
        addItem(2, 525, 450, 275, 20, 0);
        addItem(2, 100, 550, 250, 20, 0);
        addItem(2, 300, 700, 400, 20, 0);
        addItem(2, 450, 800, 100, 20, 0);

        //portals
        addItem(2, 475, 1050, 50, 20, 1);

    }

};

#endif //DAI_MAKAI_MURA_GAMEMAP_H
