#pragma once

#include "BlockInputs.h"
#include "BlockOutputs.h"
#include "ccTypes.h"

/// A class storing block data.
class BlockStructor {
protected:
    BlockStructor() {}
public:
    /// The color of the block.
    cocos2d::ccColor3B blockColor {255, 255, 255};
    /// Tells if this block uses wires or no.
    bool isAWireBlock;
    /// Tells whether the block is a connector/jigsaw block.
    bool isAConnectorBlock;
    /// Tells whether if the block is a "swatch" block (It's like a sample).
    bool isASwatch;
    /// The name of the block
    std::string name;
    /// The block's description
    std::string description;
    /// The inputs of a block. Will look different if wired.
    BlockInputs* inputs;
    /// For wire blocks, points to the outputs.
    BlockOutputs* outputs;
    /// For Non-Wire blocks. Points to the block it's connected to.
    BlockStructor* connectedBlock;

    static BlockStructor* create();
    static BlockStructor* createAsSwatch();
    BlockStructor* duplicate();
    BlockStructor* copy();
    void runActionSingle();
};