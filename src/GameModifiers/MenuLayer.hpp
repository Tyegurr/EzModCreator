#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

#include "../EzModCreator.hpp"

using namespace geode::prelude;
class $modify(ModdedMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto ModButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("ModButtonSprite.png"_spr),
            this,
            menu_selector(ModdedMenuLayer::onModButton)
        );

        auto bottomMenu = this->getChildByID("bottom-menu");
        bottomMenu->addChild(ModButton);
        ModButton->setID("ProgrammableEventsModButton"_spr);

        bottomMenu->updateLayout();

        return true;
    }
    
    void onModButton(CCObject* sender)
    {
        EzModCreator::get()->OpenModListLayer();
    }
}; // ok but how do i detect if it's about to be destroyed or we're leaving the menu..