#ifndef DAI_MAKAI_MURA_ITEMMODEL_H
#define DAI_MAKAI_MURA_ITEMMODEL_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class ItemModel
{

private:
    int mLvl;
    int mType;
    Vector2i mStartPos;
    Vector2i mSize;

public:
    ItemModel(int mLvl, Vector2i mStartPos, Vector2i mSize, int mType)
    {
        this->mLvl = mLvl;
        this->mStartPos = mStartPos;
        this->mSize = mSize;
        this->mType = mType;
    }

    ~ItemModel()
    {

    }

    int getLvl()
    {
        return mLvl;
    }

    int getType()
    {
        return mType;
    }

    Vector2i getStartPos()
    {
        return mStartPos;
    }

    Vector2i getSize()
    {
        return mSize;
    }

};

#endif //DAI_MAKAI_MURA_ITEMMODEL_H
