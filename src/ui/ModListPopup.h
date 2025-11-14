#pragma once

#include <Geode/Geode.hpp>
#include <string>
using namespace geode::prelude;

class ModListPopup : public geode::Popup<std::string const&> // popup deez nuts
{
protected:
    bool setup(std::string const& value) override;
    void setupUI();

    CCSprite* ModListLogo;
    CCScale9Sprite* ModListBackgroundSprite;
    CCScale9Sprite* ModInfoBackgroundSprite;


    bool transitioningToCreationLab;

    CCMenuItemSpriteExtra* CreateNewModButton;

    void onCreateNewModButton(CCObject* sender);
public:
    ModListPopup() {}
    static ModListPopup* create(std::string const& text);
};