#include "EzModCreator.hpp"

EzModCreator* EzModCreator::instancePtr = nullptr; // it's a singleton afterall

void EzModCreator::OpenModListLayer() {
    if (_modListLayerOpen == true) return;

    _modListLayer = ModListLayer::create();
    CCScene::get()->addChild(_modListLayer);
    _modListLayerOpen = true;
}