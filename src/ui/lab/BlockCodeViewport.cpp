#include "BlockCodeViewport.h"
#include "../ui.h"
#include "../../EzModCreator.hpp"
#include "Geode/cocos/cocoa/CCGeometry.h"
#include "Geode/cocos/touch_dispatcher/CCTouch.h"
#include "Geode/utils/cocos.hpp"
#include <Geode/binding/PlatformToolbox.hpp>

void BlockCodeViewport::updateGeom() {
    CCSize screenSize = CCScene::get()->getContentSize();
    if (EzModCreator::get()->getCreationLabLayer() == nullptr) return; // it's kinda like a failsafe..

    _mouseIsInsideMe = isMouseInsideRect({160.0f, 0.0f, screenSize.width - 160.0f, screenSize.height - 17.0f});
    
    this->setPosition({screenSize.width, 0.0f});
    this->setContentSize({screenSize.width - 160.0f, screenSize.height - 16.0f});
    CCSize currentSize = this->getContentSize();
    _dottedBackground->setTextureRect({_camPos.x, _camPos.y, screenSize.width - 160.0f, screenSize.height - 16.0f});
    _dottedBackground->setPosition({currentSize.width / 2, currentSize.height / 2});

    //_blockAnchorPoint->setPosition({ _camPos.x, _camPos.y });
}

bool BlockCodeViewport::init() {
    if (!CCMenu::init()) return false;

    _camPos.x = 0.0f;
    _camPos.y = 0.0f;

    this->setID("block-code-viewport");
    this->setZOrder(-2);
    this->setAnchorPoint({1.0f, 0.0f});

    _dottedBackground = CCSprite::create();
    _dottedBackground->initWithFile("DottedGrid_Dark.png"_spr);

    ccTexParams dottedBackgroundTexParams { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
    _dottedBackground->getTexture()->setTexParameters(&dottedBackgroundTexParams);
    this->addChildAtPosition(_dottedBackground, Anchor::Center); // and by doing this we give the parent a parasite! I MEAN ANCHOR LAYOUT!!!!

    _blockAnchorPoint = CCNode::create();
    _blockAnchorPoint->setID("block-anchor-point");
    _blockAnchorPoint->setPosition({0.0f, 0.0f});

    this->updateLayout();
    setTouchEnabled(true);

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

    if (_touching) {
        // holy geometry
        CCPoint currentMousePos = geode::cocos::getMousePos();
        _camPos.x = _camPosOnTouchFrame.x + (_mousePosOnTouchFrame.x - currentMousePos.x);
        _camPos.y = _camPosOnTouchFrame.y + (currentMousePos.y - _mousePosOnTouchFrame.y);
    }
}

bool BlockCodeViewport::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent) {
    _touching = true;
    _camPosOnTouchFrame = _camPos;
    _mousePosOnTouchFrame = geode::cocos::getMousePos();
    return true;
}
void BlockCodeViewport::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent) {
    _touching = false;
}