#pragma once

#include <Geode/Geode.hpp>
#include <Geode/binding/ButtonSprite.hpp>

using namespace geode::prelude;
class ModListLayer : public CCLayer {
protected:
    bool init();

    CCSprite* DimBackgroundSprite;
    CCNode* ListAnchor;
    CCSprite* BackingUI;
    CCSprite* ModListTitle;

    CCSprite* ListAreaBackground;
    CCSprite* InfoAreaBackground;

    ButtonSprite* CreateNewModButton;
public:
    ModListLayer() {}
    static ModListLayer* create();
};