#include "ModCreationLabLayer.h"

bool ModCreationLabLayer::init() {
    if (!CCLayer::init()) return false;

    _labTopBar = LabTopBar::create();
    this->addChild(_labTopBar);
    _blockSelectorPanel = BlockSelectorPanel::create();
    this->addChild(_blockSelectorPanel);
    _blockCodeViewport = BlockCodeViewport::create();
    this->addChild(_blockCodeViewport);

    return true;
}

ModCreationLabLayer* ModCreationLabLayer::create() {
    ModCreationLabLayer* layer = new ModCreationLabLayer();
    layer->init();
    return layer;
}