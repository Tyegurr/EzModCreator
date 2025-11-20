// here we foocking go
#pragma once

#include "BlockInputs.h"
//#include "BlockOutputs.h"
#include "ccTypes.h"

class BlockStructor {
protected:
    BlockStructor() {}
public:
    cocos2d::ccColor3B blockColor {255, 255, 255};
    bool isASwatch;
    std::string name;
    std::string description;
    BlockInputs* inputs;
    BlockStructor* connectedBlock;

    static BlockStructor* create();
    static BlockStructor* createAsSwatch();
    BlockStructor* duplicate();
    BlockStructor* copy();
    void runActionSingle();
};