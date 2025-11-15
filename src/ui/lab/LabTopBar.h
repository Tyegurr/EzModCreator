#pragma once

#include <Geode/Geode.hpp>
using namespace geode::prelude;

class LabTopBar : public CCMenu {
protected:
    bool init() override;

    CCSprite* _backgroundSprite;
    CCSprite* _creationLabLogoSprite;

    CCMenuItemSpriteExtra* NewCreationButton;
    CCMenuItemSpriteExtra* OpenCreationButton;
    CCMenuItemSpriteExtra* SaveCreationButton;
    CCMenuItemSpriteExtra* SaveCreationAsButton;
public:
    LabTopBar() {}
    static LabTopBar* create();

    void update(float delta) override;
};