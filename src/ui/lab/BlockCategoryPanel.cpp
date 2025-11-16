#include "BlockCategoryPanel.h"
#include "../ui.h"
#include <cmath>

void BlockCategoryPanel::updateGeom() {
    CCSize sceneSize = CCScene::get()->getContentSize();

    this->setContentSize({32.0f, sceneSize.height - 16.0f});
    CCSize thisSize = this->getContentSize();
    _backgroundSprite->setContentSize(thisSize);
    _scrollArea->setContentSize(thisSize);
}
bool BlockCategoryPanel::init() {
    if (!CCMenu::init()) return false;

    _timeMouseHasBeenIn = 0.0f;
    _lastDelta = 0.0f;
    _mouseIn = false;

    _testNode = CCNode::create();
    _testNode->setID("test node");
    this->addChild(_testNode);

    this->setContentSize({32.0f, 0.0f});
    _backgroundSprite = CCScale9Sprite::createWithSpriteFrameName("PlainWhiteSquare.png"_spr);
    _backgroundSprite->setID("Background Sprite");
    _backgroundSprite->setAnchorPoint({0.0f, 0.0f});
    _backgroundSprite->setColor({0, 75, 91});
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
    _lastDelta = delta;
    updateGeom();

    if (_mouseIn) {
        _timeMouseHasBeenIn += delta;
    } else {
        _timeMouseHasBeenIn = 0.0f;
    }
}