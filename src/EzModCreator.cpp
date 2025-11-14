#include "EzModCreator.hpp"

EzModCreator* EzModCreator::instancePtr = nullptr; // it's a singleton afterall

void EzModCreator::OpenModListLayer() {
    //if (_modListLayerOpen == true) return;

    _modListPopup = ModListPopup::create("EZ! Mod Creator");
    CCScene::get()->addChild(_modListPopup);
    _modListLayerOpen = true;
}