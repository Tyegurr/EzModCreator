#include "ModCreationLabLayer.h"

bool ModCreationLabLayer::init() {
    if (!CCLayer::init()) return false;

    _labTopBar = LabTopBar::create();
    this->addChild(_labTopBar);

    return true;
}

ModCreationLabLayer* ModCreationLabLayer::create() {
    ModCreationLabLayer* layer = new ModCreationLabLayer();
    layer->init();
    return layer;
}