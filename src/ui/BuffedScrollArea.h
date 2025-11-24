#pragma once

#include "Geode/cocos/base_nodes/CCNode.h"
#include "Geode/cocos/sprite_nodes/CCSprite.h"
#include "Geode/ui/Layout.hpp"
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class BuffedScrollArea : public CCMenu {
protected:
    void updateGeom();
    bool init(bool scrollBarVisible);

    CCLayerColor* _stencil;
    CCClippingNode* _clippingNode;
    ColumnLayout* _scrollLayout;

    bool _scrollBarVisible;
    CCNode* _scrollNodeMain;
public:
    BuffedScrollArea() {}
    static BuffedScrollArea* create(bool scrollBarVisible);

    CCNode* getMainScrollNode();

    void update(float delta);
};