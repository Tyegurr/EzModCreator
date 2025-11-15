#pragma once

#include <Geode/Geode.hpp>
#include "../BuffedScrollArea.h"
using namespace geode::prelude;

class BlockCategoryPanel : public CCMenu {
protected:
    void updateGeom();
    bool init();

    CCScale9Sprite* _backgroundSprite;
    BuffedScrollArea* _scrollArea;
public:
    BlockCategoryPanel() {}
    static BlockCategoryPanel* create();

    void update(float delta);
};