#include "BlockCodeViewport.h"
#include "../ui.h"
#include "../../EzModCreator.hpp"

void BlockCodeViewport::updateGeom() {
    CCSize screenSize = CCScene::get()->getContentSize();
    if (EzModCreator::get()->getCreationLabLayer() == nullptr) return;

    _mouseIsInsideMe = isMouseInsideRect({160.0f, 0.0f, screenSize.width - 160.0f, screenSize.height - 16.0f});

    if (_mouseIsInsideMe && EzModCreator::get()->getCreationLabLayer()->isActivelyPressing()) {
        _dottedBackground->setColor({0, 255, 0});
    } else {
        _dottedBackground->setColor({255, 255, 255});
    }
    
    this->setPosition({screenSize.width, 0.0f});
    this->setContentSize({screenSize.width - 160.0f, screenSize.height - 16.0f});
    CCSize currentSize = this->getContentSize();
    _dottedBackground->setTextureRect({_dragPos.x, _dragPos.y, screenSize.width - 160.0f, screenSize.height - 16.0f});
    _dottedBackground->setPosition({currentSize.width / 2, currentSize.height / 2});
}

bool BlockCodeViewport::init() {
    if (!CCMenu::init()) return false;

    _dragPos.x = 0.0f;
    _dragPos.y = 0.0f;

    this->setID("Block Code Viewport");
    this->setZOrder(-2);
    this->setAnchorPoint({1.0f, 0.0f});

    _dottedBackground = CCSprite::create();
    _dottedBackground->initWithFile("DottedGrid_Dark.png"_spr);

    ccTexParams dottedBackgroundTexParams { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
    _dottedBackground->getTexture()->setTexParameters(&dottedBackgroundTexParams);
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