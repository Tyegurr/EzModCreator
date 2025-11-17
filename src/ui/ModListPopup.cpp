#include "ModListPopup.h"
#include "ModCreationLabLayer.h"

bool ModListPopup::setup(std::string const& value) {
    return true;
}

void ModListPopup::setupUI() {
    m_noElasticity = true;

    m_mainLayer->setContentSize({324.0, 200.0});
    m_mainLayer->updateLayout(true);
    m_mainLayer->setScale(0.0, 0.0);

    // customizing color
    m_bgSprite->setColor({0, 139, 255});

    // making some awesome ui
    ModListLogo = CCSprite::createWithSpriteFrameName("ModListTitle.png"_spr);
    ModListLogo->setID("mod-list-logo");
    ModListLogo->setZOrder(3);
    ModListLogo->setScale(0.93);
    m_buttonMenu->addChildAtPosition(ModListLogo, Anchor::Center);
    ModListLogo->setPositionY(200.0);

    ModListBackgroundSprite = CCScale9Sprite::create("GJ_square06.png");
    ModListBackgroundSprite->setID("mod-list-background-sprite");
    ModListBackgroundSprite->setPosition({60.0, 100.0});
    ModListBackgroundSprite->setContentSize({100.0, 180.0});
    ModListBackgroundSprite->setColor({0, 83, 165});
    ModListBackgroundSprite->setZOrder(-1);
    m_buttonMenu->addChild(ModListBackgroundSprite);

    ModInfoBackgroundSprite = CCScale9Sprite::create("GJ_square06.png");
    ModInfoBackgroundSprite->setID("mod-info-background-sprite");
    ModInfoBackgroundSprite->setContentSize({200.0, 180.0});
    ModInfoBackgroundSprite->setColor({0, 83, 165});
    ModInfoBackgroundSprite->setZOrder(-1);
    m_buttonMenu->addChildAtPosition(ModInfoBackgroundSprite, Anchor::Center);
    ModInfoBackgroundSprite->setPositionX(215.0);

    // creating buttons
    CreateNewModButton = CCMenuItemSpriteExtra::create(
        CircleButtonSprite::createWithSpriteFrameName("TEXT_New.png"_spr),
        this,
        menu_selector(ModListPopup::onCreateNewModButton)
    );
    CreateNewModButton->setID("create-new-mod-button");
    m_buttonMenu->addChildAtPosition(CreateNewModButton, Anchor::Center);
    CreateNewModButton->setPosition({356.0, 100.0});

    // tweening because that's awesome
    CCEaseElasticOut* MainLayerScaleTween = CCEaseElasticOut::create(CCScaleTo::create(0.8, 1.0), 0.5);
    m_mainLayer->runAction(MainLayerScaleTween);
}

// button callbacks
void ModListPopup::onCreateNewModButton(CCObject* sender) {
    if (transitioningToCreationLab == true) return;
    transitioningToCreationLab = true;
    log::info("starting transition to mod creation lab");

    CCScene* newScene = CCScene::create();
    ModCreationLabLayer* CreationLab = ModCreationLabLayer::create();
    newScene->addChild(CreationLab);

    CCTransitionFade* sceneTransitionFade = CCTransitionFade::create(0.5, newScene);
    CCDirector::get()->pushScene(sceneTransitionFade);
}

ModListPopup* ModListPopup::create(std::string const& text) {
    ModListPopup* popup = new ModListPopup();
    if (popup->initAnchored(260.0f, 160.0f, text)) {
        popup->autorelease();
        popup->setupUI();
        return popup;
    }
    delete popup;
    return nullptr;
}