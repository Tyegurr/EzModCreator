#pragma once

#include "lab/labUI.h"

#include <Geode/Geode.hpp>
using namespace geode::prelude;

class ModCreationLabLayer : public CCLayer {
protected:
    bool init() override;

    LabTopBar* _labTopBar;
    BlockSelectorPanel* _blockSelectorPanel;
    BlockCodeViewport* _blockCodeViewport;

    bool _touching;
public:
    ModCreationLabLayer() {}
    static ModCreationLabLayer* create();

    bool isActivelyPressing();
    bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent) override;
    void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent) override;
};