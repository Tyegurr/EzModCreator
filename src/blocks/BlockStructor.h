// here we foocking go
#pragma once

#include "BlockInputs.h"
#include "BlockOutputs.h"

class BlockStructor {
protected:
    BlockStructor() {}
public:
    std::string name;
    std::string description;
    BlockInputs* inputs;
    BlockOutputs* outputs;

    static BlockStructor* create();
};