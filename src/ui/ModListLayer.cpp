#include "ModListLayer.h"

bool ModListLayer::init() {
    if (!CCLayer::init()) return false;

    this->setID("Mod List Layer");

    DimBackgroundSprite = CCSprite::createWithSpriteFrameName("BlackSquare.png"_spr);
    DimBackgroundSprite->setOpacity(112);
    DimBackgroundSprite->setScale(64.0);
    DimBackgroundSprite->setID("Dim Background Sprite");
    this->addChild(DimBackgroundSprite);

    ListAnchor = CCNode::create();
    ListAnchor->setPosition({284.5, 150});
    ListAnchor->setScale(0.0, 0.0);
    ListAnchor->setID("List Anchor");
    this->addChild(ListAnchor);

    BackingUI = CCSprite::createWithSpriteFrameName("ModListBackingUI.png"_spr);
    BackingUI->setID("Backing UI");
    ListAnchor->addChild(BackingUI);

    // scroll area background sprite
    ListAreaBackground = CCSprite::createWithSpriteFrameName("ModListBackground.png"_spr); // thin boi
    ListAreaBackground->setID("List Area Background");
    ListAreaBackground->setPositionX(-92.0);
    ListAnchor->addChild(ListAreaBackground);
    
    InfoAreaBackground = CCSprite::createWithSpriteFrameName("ModInfoBackground.png"_spr); // THICC BOI
    InfoAreaBackground->setID("Info Area Background");
    InfoAreaBackground->setPositionX(56.0);
    ListAnchor->addChild(InfoAreaBackground);

    // button timess


    // making title
    ModListTitle = CCSprite::createWithSpriteFrameName("ModListTitle.png"_spr);
    ModListTitle->setPositionY(115);
    ModListTitle->setScale(0.85);
    ModListTitle->setZOrder(2);
    ListAnchor->addChild(ModListTitle);


    // tweening it
    CCEaseElasticOut* ListAnchorScaleTween = CCEaseElasticOut::create(CCScaleTo::create(0.8, 1.0), 0.5);
    ListAnchor->runAction(ListAnchorScaleTween);

    return true;
}

ModListLayer* ModListLayer::create() {
    ModListLayer* layer = new ModListLayer();
    layer->init();
    return layer;
}