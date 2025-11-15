#pragma once

#include <Geode/Geode.hpp>
using namespace geode::prelude;

class BlockCategoryButton : public CCNode {
protected:
    bool init(std::string name, cocos2d::ccColor3B const& color);
public:
    BlockCategoryButton() {}
    static BlockCategoryButton* create(std::string name, cocos2d::ccColor3B const& color);
};