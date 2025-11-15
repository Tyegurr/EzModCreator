#include "BlockCategoryButton.h"

bool BlockCategoryButton::init(std::string name, cocos2d::ccColor3B const& color) {
    if (!CCNode::init()) return false;
    return true;
}

BlockCategoryButton* BlockCategoryButton::create(std::string name, cocos2d::ccColor3B const& color) {
    BlockCategoryButton* node = new BlockCategoryButton();
    node->init(name, color);
    return node;
}