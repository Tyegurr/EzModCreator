#include "BlockCategoryPanel.h"
#include <vector>
#include "../../blocks/BlockMapper.h"
#include "BlockCategoryButton.h"
#include "Geode/cocos/cocoa/CCGeometry.h"

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
    _testNode->setID("test-node");
    this->addChild(_testNode);

    this->setContentSize({32.0f, 0.0f});
    _backgroundSprite = CCScale9Sprite::createWithSpriteFrameName("PlainWhiteSquare.png"_spr);
    _backgroundSprite->setID("background-sprite");
    _backgroundSprite->setAnchorPoint({0.0f, 0.0f});
    _backgroundSprite->setColor({0, 75, 91});
    this->addChild(_backgroundSprite);

    _scrollArea = BuffedScrollArea::create(true);
    _scrollArea->setID("scroll-area");
    _scrollArea->setAnchorPoint({0.0f, 0.0f });
    _scrollArea->setPosition({0.0f, 0.0f });
    this->addChild(_scrollArea);

    std::vector<category_metadata> allMetadata = BlockMapper::get()->getAllCategoryMetadata();
    std::vector<BlockCategoryButton*> catBtnVec;
    for (category_metadata metadata : allMetadata) {
        BlockCategoryButton* btn = BlockCategoryButton::create(metadata.name, metadata.color);
        btn->setPosition({16.0f, 16.0f});
        _scrollArea->getMainScrollNode()->addChild(btn);
        _scrollArea->getMainScrollNode()->updateLayout();
        catBtnVec.push_back(btn);
    }
    for (BlockCategoryButton* btn : catBtnVec) {
        CCPoint currentPos = btn->getPosition();
        btn->setPositionX(16.0f);
        btn->setPositionY(currentPos.y - 16.5f);
    }

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