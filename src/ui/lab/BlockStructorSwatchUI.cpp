#include "BlockStructorSwatchUI.h"
#include "GUI/CCControlExtension/CCScale9Sprite.h"
#include "Geode/cocos/cocoa/CCGeometry.h"
#include "Geode/cocos/label_nodes/CCLabelBMFont.h"
#include "Geode/cocos/menu_nodes/CCMenuItem.h"

bool BlockStructorSwatchUI::init(const cocos2d::CCSize& size) {
    if (!CCMenuItem::init()) return false;

    this->setContentSize({ size.width, size.height + (_swatchRef->getNumberOfOutputs() * 16) });

    _swatchBackgroundSprite = CCScale9Sprite::create("GJ_square06.png");
    _swatchBackgroundSprite->setContentSize(this->getContentSize());
    _swatchBackgroundSprite->setColor(_swatchRef->blockColor);
    this->addChildAtPosition(_swatchBackgroundSprite, Anchor::Center);

    _nameLabel = CCLabelBMFont::create(_swatchRef->name.c_str(), "bigFont.fnt");
    _nameLabel->setScale(0.27f);
    this->addChildAtPosition(_nameLabel, Anchor::Top);
    _nameLabel->setPositionY(_nameLabel->getPositionY() - 9.0f);

    return true;
}

BlockStructorSwatchUI* BlockStructorSwatchUI::create(const cocos2d::CCSize& size, BlockStructor* ref) {
    BlockStructorSwatchUI* menuItem = new BlockStructorSwatchUI();
    menuItem->_swatchRef = ref;
    menuItem->init(size);
    return menuItem;
}