#pragma once

#include <Geode/Geode.hpp>
#include "../../blocks/BlockStructor.h"
using namespace geode::prelude;

class UIBlock : public CCMenu {
private:
    bool _isASwatch;
    BlockStructor* _rawBlockData;
public:
    static UIBlock* createFromBlockStructor(const BlockStructor& ref);
    static UIBlock* createFromBlockStructorAsSwatch(const BlockStructor& ref);
};