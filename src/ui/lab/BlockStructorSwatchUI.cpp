#include "BlockStructorSwatchUI.h"
#include "Geode/cocos/cocoa/CCGeometry.h"
#include "Geode/cocos/menu_nodes/CCMenuItem.h"

bool BlockStructorSwatchUI::init(const cocos2d::CCSize& size) {
    if (!CCMenuItem::init()) return false;

    this->setContentSize(size);

    return true;
}

BlockStructorSwatchUI* BlockStructorSwatchUI::create(const cocos2d::CCSize& size, BlockStructor* ref) {
    BlockStructorSwatchUI* menuItem = new BlockStructorSwatchUI();
    menuItem->_swatchRef = ref;
    menuItem->init(size);
    return menuItem;
}