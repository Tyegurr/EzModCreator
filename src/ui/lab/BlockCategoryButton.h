#pragma once

#include "Geode/cocos/label_nodes/CCLabelBMFont.h"
#include "Geode/cocos/sprite_nodes/CCSprite.h"
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class BlockCategoryButton : public CCMenu {
protected:
    bool init(std::string name, cocos2d::ccColor3B const& color);

    CCSprite* _spriteIcon;
    CCLabelBMFont* _label;
public:
    BlockCategoryButton() {}
    static BlockCategoryButton* create(std::string name, cocos2d::ccColor3B const& color);
};