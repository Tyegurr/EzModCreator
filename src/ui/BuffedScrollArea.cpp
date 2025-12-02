#include "BuffedScrollArea.h"
#include "Geode/cocos/base_nodes/CCNode.h"
#include "Geode/ui/Layout.hpp"
#include "Geode/ui/SimpleAxisLayout.hpp"

void BuffedScrollArea::updateGeom() {
    CCSize thisSize = this->getContentSize();
    _stencil->setContentSize({thisSize.width, thisSize.height});
    _stencil->setPosition({0.0f, 0.0f});
    _scrollNodeMain->setContentSize(thisSize);
    _clippingNode->setContentSize(thisSize);
}
bool BuffedScrollArea::init(bool scrollbarVisible) {
    if (!CCMenu::init()) return false;
    
    _scrollBarVisible = scrollbarVisible;

    _stencil = CCLayerColor::create();
    _stencil->setID("clipping-stencil");
    _stencil->setAnchorPoint({0.0f, 0.0f});
    _stencil->setPosition({0.0f, 0.0f});
    this->addChild(_stencil);

    _clippingNode = CCClippingNode::create(_stencil);
    _clippingNode->setAlphaThreshold(1.0f);
    _clippingNode->setID("scroll-clipping-node");
    this->addChild(_clippingNode);

    _scrollLayout = ColumnLayout::create();
    _scrollLayout->setAxisAlignment(AxisAlignment::End);
    _scrollLayout->setAutoScale(false);
    _scrollLayout->setGap(0.0f);
    _scrollLayout->setAxisReverse(true);

    _scrollNodeMain = CCNode::create();
    _scrollNodeMain->setLayout(_scrollLayout);
    _scrollNodeMain->setID("scroll-node-main");
    _clippingNode->addChildAtPosition(_scrollNodeMain, Anchor::Top);
    _scrollNodeMain->updateLayout();

    scheduleUpdate();
    updateGeom();
    return true;
}

BuffedScrollArea* BuffedScrollArea::create(bool scrollbarVisible) {
    BuffedScrollArea* node = new BuffedScrollArea();
    node->init(scrollbarVisible);
    return node;
}

CCNode* BuffedScrollArea::getMainScrollNode() {
    return _scrollNodeMain;
}

void BuffedScrollArea::update(float delta) {
    updateGeom();
}