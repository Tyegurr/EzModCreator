#include "BlockCodeViewport.h"

void BlockCodeViewport::updateGeom() {
    CCSize screenSize = CCScene::get()->getContentSize();

    this->setPosition({screenSize.width, 0.0f});
    this->setContentSize({screenSize.width - 160.0f, screenSize.height - 16.0f});
    CCSize currentSize = this->getContentSize();
    _dottedBackground->setTextureRect({_dragPos.x, _dragPos.y, screenSize.width - 160.0f, screenSize.height - 16.0f});
    _dottedBackground->setPosition({currentSize.width / 2, currentSize.height / 2});
}

bool BlockCodeViewport::init() {
    if (!CCMenu::init()) return false;

    this->setID("Block Code Viewport");
    this->setZOrder(-2);
    this->setAnchorPoint({1.0f, 0.0f});

    _dottedBackground = CCSprite::create();
    _dottedBackground->initWithFile("DottedGrid_Dark.png"_spr);

    ccTexParams dottedBackgroundTexParams { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };

    _dottedBackground->getTexture()->setTexParameters(&dottedBackgroundTexParams);

    //TODO: make this a tiling/repeating sprite or somethin like that
    this->addChildAtPosition(_dottedBackground, Anchor::Center); // and by doing this we give the parent a parasite! I MEAN ANCHOR LAYOUT!!!!

    this->updateLayout();

    scheduleUpdate();
    updateGeom();
    return true;
}

BlockCodeViewport* BlockCodeViewport::create() {
    BlockCodeViewport* menu = new BlockCodeViewport();
    menu->init();
    return menu;
}

void BlockCodeViewport::update(float delta) {
    updateGeom();
}