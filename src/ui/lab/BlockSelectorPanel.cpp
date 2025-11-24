#include "BlockSelectorPanel.h"
#include "BlockStructorSwatchUI.h"
#include <vector>


void BlockSelectorPanel::fitToScreen() {
    CCSize sceneSize = CCScene::get()->getContentSize();
    this->setContentSize({160.0f, sceneSize.height - 16.0f});
    _scrollArea->setContentSize({128.0f, sceneSize.height - 16.5f});
    _background->setContentSize(this->getContentSize());
}
bool BlockSelectorPanel::init() {
    if (!CCMenu::init()) return false;

    scheduleUpdate();
    this->setID("block-selector-panel");
    this->setAnchorPoint({0.0f, 0.0f});
    this->setPosition({0.0f, 0.0f});
    this->setZOrder(-1);

    _background = CCScale9Sprite::createWithSpriteFrameName("PlainWhiteSquare.png"_spr);
    _background->setID("background");
    _background->setAnchorPoint({0.0f, 0.0f});
    _background->setColor({7, 22, 62});
    this->addChild(_background);

    _blockCategoryPanel = BlockCategoryPanel::create();
    _blockCategoryPanel->setID("block-category-panel");
    _blockCategoryPanel->setAnchorPoint({0.0f, 0.0f});
    _blockCategoryPanel->setPosition({0.0f, 0.0f});
    this->addChild(_blockCategoryPanel);

    _scrollArea = BuffedScrollArea::create(false);
    _scrollArea->setPositionX(32.0f);
    _scrollArea->setPositionY(0.0f);
    this->addChild(_scrollArea);

    // fitting stuff to screen geom.
    fitToScreen();

    return true;
}

BlockSelectorPanel* BlockSelectorPanel::create() {
    BlockSelectorPanel* menu = new BlockSelectorPanel();
    menu->init();
    return menu;
}

void BlockSelectorPanel::refreshScrollAreaForBlockCategory(const BlockCategory& ref) {
    // we now need to get all the swatches and make their respective UIs
    const std::vector<BlockStructor*>& swatches = ref.getAllSwatches();
    for (BlockStructor* block : swatches) {
        BlockStructorSwatchUI* swatch = BlockStructorSwatchUI::create({120, 42}, block);
        _scrollArea->getMainScrollNode()->addChild(swatch);
        _scrollArea->getMainScrollNode()->updateLayout();
    }
}
void BlockSelectorPanel::update(float delta) {
    fitToScreen();
}