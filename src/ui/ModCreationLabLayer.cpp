#include "ModCreationLabLayer.h"
#include "../EzModCreator.hpp"

#include "../blocks/BlockMapper.h"

bool ModCreationLabLayer::init() {
    if (!CCLayer::init()) return false;

    BlockMapper::get()->initAllKnownEverything();
    
    _labTopBar = LabTopBar::create();
    this->addChild(_labTopBar);
    _blockSelectorPanel = BlockSelectorPanel::create();
    this->addChild(_blockSelectorPanel);
    _blockCodeViewport = BlockCodeViewport::create();
    this->addChild(_blockCodeViewport);

    EzModCreator::get()->setCreationLabLayerCurrent(this);
    setTouchEnabled(true);

    return true;
}

ModCreationLabLayer* ModCreationLabLayer::create() {
    ModCreationLabLayer* layer = new ModCreationLabLayer();
    layer->init();
    return layer;
}

bool ModCreationLabLayer::isActivelyPressing() {
    return _touching;
}
bool ModCreationLabLayer::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent) {
    _touching = true;
    return true;
}
void ModCreationLabLayer::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent) {
    _touching = false;
}