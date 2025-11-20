#pragma once

#include <Geode/Geode.hpp>
#include "BlockCategoryPanel.h"
#include "../BuffedScrollArea.h"
#include "../../blocks/BlockCategory.hpp"
using namespace geode::prelude;

class BlockSelectorPanel : public CCMenu {
protected:
    void fitToScreen();
    bool init() override;

    CCScale9Sprite* _background;
    BlockCategoryPanel* _blockCategoryPanel;
    BuffedScrollArea* _scrollArea;
public:
    BlockSelectorPanel() {}
    static BlockSelectorPanel* create();
    
    void refreshScrollAreaForBlockCategory(const BlockCategory& ref);
    void update(float delta) override;
};