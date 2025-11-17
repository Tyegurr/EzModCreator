#include "BuffedScrollArea.h"

void BuffedScrollArea::updateGeom() {
    CCSize thisSize = this->getContentSize();
    _stencil->setContentSize({thisSize.width, thisSize.height});
    _stencil->setPosition({0.0f, 0.0f});
    _clippingNode->setContentSize(thisSize);
}
bool BuffedScrollArea::init(bool scrollbarVisible) {
    if (!CCNode::init()) return false;
    
    _scrollBarVisible = scrollbarVisible;

    _stencil = CCNode::create();
    _stencil->setID("clipping-stencil");
    _stencil->setAnchorPoint({0.0f, 0.0f});
    _stencil->setPosition({0.0f, 0.0f});
    this->addChild(_stencil);

    _clippingNode = CCClippingNode::create(_stencil);
    this->addChild(_clippingNode);

    scheduleUpdate();
    updateGeom();
    return true;
}

BuffedScrollArea* BuffedScrollArea::create(bool scrollbarVisible) {
    BuffedScrollArea* node = new BuffedScrollArea();
    node->init(scrollbarVisible);
    return node;
}

void BuffedScrollArea::update(float delta) {
    updateGeom();
}