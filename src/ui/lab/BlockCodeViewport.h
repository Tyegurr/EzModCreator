#pragma once

#include <Geode/Geode.hpp>
using namespace geode::prelude;

#include "../../math/math.h"

class BlockCodeViewport : public CCMenu {
protected:
    void updateGeom();
    bool init() override;

    CCSprite* _dottedBackground;
    vec2 _dragPos { 0.0f, 0.0f };
public:
    BlockCodeViewport() {}
    static BlockCodeViewport* create();

    void update(float delta) override;
};