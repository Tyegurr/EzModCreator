#pragma once
#include "GUI/CCControlExtension/CCScale9Sprite.h"
#include "Geode/cocos/cocoa/CCGeometry.h"
#include "Geode/cocos/menu_nodes/CCMenuItem.h"
#include <Geode/Geode.hpp>
#include "../../blocks/BlockStructor.hpp"
using namespace geode::prelude;

class BlockStructorSwatchUI : public CCMenuItem {
protected:
    BlockStructor* _swatchRef;
    CCScale9Sprite* _swatchBackgroundSprite;
    CCLabelBMFont* _nameLabel;

    bool init(const cocos2d::CCSize& size);
    BlockStructorSwatchUI() {}
public:
    static BlockStructorSwatchUI* create(const cocos2d::CCSize& size, BlockStructor* ref);
};