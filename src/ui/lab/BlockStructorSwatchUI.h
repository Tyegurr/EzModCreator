#pragma once
#include "Geode/cocos/cocoa/CCGeometry.h"
#include "Geode/cocos/menu_nodes/CCMenuItem.h"
#include <Geode/Geode.hpp>
#include "../../blocks/BlockStructor.hpp"
using namespace geode::prelude;

class BlockStructorSwatchUI : CCMenuItem {
protected:
    BlockStructor* _swatchRef;

    bool init(const cocos2d::CCSize& size);
    BlockStructorSwatchUI() {}
public:
    static BlockStructorSwatchUI* create(const cocos2d::CCSize& size, BlockStructor* ref);
};