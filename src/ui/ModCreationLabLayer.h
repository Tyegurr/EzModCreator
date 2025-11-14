#pragma once

#include "lab/LabTopBar.h"

#include <Geode/Geode.hpp>
using namespace geode::prelude;

class ModCreationLabLayer : public CCLayer {
protected:
    bool init() override;

    LabTopBar* _labTopBar;
public:
    ModCreationLabLayer() {}
    static ModCreationLabLayer* create();
};