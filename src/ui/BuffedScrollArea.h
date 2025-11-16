#pragma once

#include <Geode/Geode.hpp>
using namespace geode::prelude;

class BuffedScrollArea : public CCNode {
protected:
    void updateGeom();
    bool init(bool scrollBarVisible);

    CCNode* _stencil;
    CCClippingNode* _clippingNode;

    bool _scrollBarVisible;
public:
    BuffedScrollArea() {}
    static BuffedScrollArea* create(bool scrollBarVisible);

    void update(float delta);
};