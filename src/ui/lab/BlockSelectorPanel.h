#pragma once

#include <Geode/Geode.hpp>
#include "BlockCategoryPanel.h"
using namespace geode::prelude;

class BlockSelectorPanel : public CCMenu {
protected:
    void fitToScreen();
    // any cool stuff should go before init
    bool init() override;

    CCScale9Sprite* _background;
    BlockCategoryPanel* _blockCategoryPanel;
public:
    BlockSelectorPanel() {}
    static BlockSelectorPanel* create();
    
    void update(float delta) override;
};