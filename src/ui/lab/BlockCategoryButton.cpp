#include "BlockCategoryButton.h"
#include "Geode/cocos/sprite_nodes/CCSprite.h"

bool BlockCategoryButton::init(std::string name, cocos2d::ccColor3B const& color) {
    if (!CCMenu::init()) return false;

    this->setContentSize({32.0f, 32.0f});

    _spriteIcon = CCSprite::createWithSpriteFrameName("RoundedBlock.png"_spr);
    _spriteIcon->setColor(color);
    _spriteIcon->setScale(1.25f);
    this->addChildAtPosition(_spriteIcon, Anchor::Center);

    return true;
}

BlockCategoryButton* BlockCategoryButton::create(std::string name, cocos2d::ccColor3B const& color) {
    BlockCategoryButton* node = new BlockCategoryButton();
    node->init(name, color);
    return node;
}