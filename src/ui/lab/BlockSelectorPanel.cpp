#include "BlockSelectorPanel.h"


void BlockSelectorPanel::fitToScreen() {
    CCSize sceneSize = CCScene::get()->getContentSize();
    this->setContentSize({160.0f, sceneSize.height - 16.0f});
    _background->setContentSize(this->getContentSize());
}
bool BlockSelectorPanel::init() {
    if (!CCMenu::init()) return false;

    scheduleUpdate();
    this->setID("block-selector-panel");
    this->setAnchorPoint({0.0f, 0.0f});
    this->setPosition({0.0f, 0.0f});
    this->setZOrder(-1);

    _background = CCScale9Sprite::createWithSpriteFrameName("PlainWhiteSquare.png"_spr);
    _background->setID("background");
    _background->setAnchorPoint({0.0f, 0.0f});
    _background->setColor({7, 22, 62});
    this->addChild(_background);

    _blockCategoryPanel = BlockCategoryPanel::create();
    _blockCategoryPanel->setID("block-category-panel");
    _blockCategoryPanel->setAnchorPoint({0.0f, 0.0f});
    _blockCategoryPanel->setPosition({0.0f, 0.0f});
    this->addChild(_blockCategoryPanel);

    // fitting stuff to screen geom.
    fitToScreen();

    return true;
}

BlockSelectorPanel* BlockSelectorPanel::create() {
    BlockSelectorPanel* menu = new BlockSelectorPanel();
    menu->init();
    return menu;
}

void BlockSelectorPanel::update(float delta) {
    fitToScreen();
}