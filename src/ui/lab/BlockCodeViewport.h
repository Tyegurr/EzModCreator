#pragma once

#include "Geode/cocos/cocoa/CCGeometry.h"
#include "Geode/cocos/touch_dispatcher/CCTouch.h"
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class BlockCodeViewport : public CCMenu {
protected:
    void updateGeom();
    bool init() override;

    CCSprite* _dottedBackground;
    CCNode* _blockAnchorPoint;
    CCPoint _camPos { 0.0f, 0.0f };
    CCPoint _camPosOnTouchFrame { 0.0f, 0.0f };
    CCPoint _mousePosOnTouchFrame { 0.0f, 0.0f };

    bool _mouseIsInsideMe;
    bool _touching;
public:
    BlockCodeViewport() {}
    static BlockCodeViewport* create();

    void update(float delta) override;

    bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent) override;
    void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent) override;
};