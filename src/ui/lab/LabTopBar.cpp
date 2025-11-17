#include "LabTopBar.h"

bool LabTopBar::init() {
    if (!CCMenu::init()) return false;

    this->setContentSize({569, 15});
    this->setPositionX(0.0);

    _backgroundSprite = CCSprite::createWithSpriteFrameName("PlainWhiteSquare.png"_spr);
    _backgroundSprite->setID("background-sprite");
    _backgroundSprite->setScaleX(128.0);
    _backgroundSprite->setScaleY(0.275);
    _backgroundSprite->setColor({ 18, 49, 68 });
    this->addChildAtPosition(_backgroundSprite, Anchor::Center);
    _backgroundSprite->draw();
    _backgroundSprite->updateTransform();

    _creationLabLogoSprite = CCSprite::createWithSpriteFrameName("CreationLabLogo.png"_spr);
    _creationLabLogoSprite->setID("creation-lab-logo");
    _creationLabLogoSprite->setScale(0.35);
    _creationLabLogoSprite->setAnchorPoint({1.025, 0.5});
    this->addChildAtPosition(_creationLabLogoSprite, Anchor::Right);
    //_creationLabLogoSprite->setAnchorPoint({0.0, 0.0});

    // buttons
    NewCreationButton = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("New"),
        this,
        nullptr
    );
    NewCreationButton->setID("new-button");
    NewCreationButton->setPosition({20.0f, 7.5f});
    NewCreationButton->m_baseScale = 0.45f;
    NewCreationButton->setScale(0.45f);
    this->addChild(NewCreationButton);

    OpenCreationButton = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Open"),
        this,
        nullptr
    );
    OpenCreationButton->setID("open-button");
    OpenCreationButton->setPosition({58.0f, 7.5f});
    OpenCreationButton->m_baseScale = 0.45f;
    OpenCreationButton->setScale(0.45f);
    this->addChild(OpenCreationButton);

    SaveCreationButton = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Save"),
        this,
        nullptr
    );
    SaveCreationButton->setID("save-button");
    SaveCreationButton->setPosition({98.0f, 7.5f});
    SaveCreationButton->m_baseScale = 0.45f;
    SaveCreationButton->setScale(0.45f);
    this->addChild(SaveCreationButton);

    SaveCreationAsButton = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Save As.."),
        this,
        nullptr
    );
    SaveCreationAsButton->setID("save-as-button");
    SaveCreationAsButton->setPosition({150.0f, 7.5f});
    SaveCreationAsButton->m_baseScale = 0.45f;
    SaveCreationAsButton->setScale(0.45f);
    this->addChild(SaveCreationAsButton);

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
    this->setPosition({screenSize.width / 2, screenSize.height - 8.0f});
}