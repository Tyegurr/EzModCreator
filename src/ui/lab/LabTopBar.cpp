#include "LabTopBar.h"

bool LabTopBar::init() {
    if (!CCMenu::init()) return false;

    this->setContentSize({569, 15});
    this->setPositionX(0.0);

    _backgroundSprite = CCSprite::createWithSpriteFrameName("PlainWhiteSquare.png"_spr);
    _backgroundSprite->setID("Background Sprite");
    _backgroundSprite->setScaleX(128.0);
    _backgroundSprite->setScaleY(0.275);
    _backgroundSprite->setColor({ 18, 49, 68 });
    this->addChildAtPosition(_backgroundSprite, Anchor::Center);
    _backgroundSprite->draw();
    _backgroundSprite->updateTransform();

    _creationLabLogoSprite = CCSprite::createWithSpriteFrameName("CreationLabLogo.png"_spr);
    _creationLabLogoSprite->setID("Creation Lab Logo");
    _creationLabLogoSprite->setScale(0.35);
    _creationLabLogoSprite->setAnchorPoint({1.025, 0.5});
    this->addChildAtPosition(_creationLabLogoSprite, Anchor::Right);
    //_creationLabLogoSprite->setAnchorPoint({0.0, 0.0});

    scheduleUpdate();

    return true;
}

LabTopBar* LabTopBar::create() {
    LabTopBar* node = new LabTopBar();
    node->init();
    return node;
}

void LabTopBar::update(float delta) {
    CCSize screenSize = CCScene::get()->getContentSize();
    this->setContentSize({screenSize.width, 16.0});
    this->setPosition({screenSize.width / 2, screenSize.height - 8.0f}); // the "it's a float i promise" method
}