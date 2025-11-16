#pragma once

#include <Geode/Geode.hpp>
using namespace geode::prelude;

class BlockCodeViewport : public CCMenu {
protected:
    void updateGeom();
    bool init() override;

    CCSprite* _dottedBackground;
    CCPoint _dragPos { 0.0f, 0.0f };

    bool _mouseIsInsideMe;
    bool _changeFrame;
public:
    BlockCodeViewport() {}
    static BlockCodeViewport* create();

    void update(float delta) override;
};