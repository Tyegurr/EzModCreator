#include "BlockCategoryPanel.h"

void BlockCategoryPanel::updateGeom() {
    CCSize sceneSize = CCScene::get()->getContentSize();

    this->setContentSize({32.0f, sceneSize.height - 16.0f});
    CCSize thisSize = this->getContentSize();
    _backgroundSprite->setContentSize(thisSize);
    _scrollArea->setContentSize(thisSize);
}
bool BlockCategoryPanel::init() {
    if (!CCMenu::init()) return false;

    _backgroundSprite = CCScale9Sprite::createWithSpriteFrameName("PlainWhiteSquare.png"_spr);
    _backgroundSprite->setID("Background Sprite");
    _backgroundSprite->setAnchorPoint({0.0f, 0.0f});
    this->addChild(_backgroundSprite);

    _scrollArea = BuffedScrollArea::create(true);
    _scrollArea->setID("Scroll Area");
    _scrollArea->setAnchorPoint({0.0f, 0.0f});
    this->addChild(_scrollArea);

    scheduleUpdate();
    updateGeom();
    return true;
}

BlockCategoryPanel* BlockCategoryPanel::create() {
    BlockCategoryPanel* menu = new BlockCategoryPanel();
    menu->init();
    return menu;
}

void BlockCategoryPanel::update(float delta) {
    updateGeom();
}